#include "WiFi_get_data.h"
#include "esp_event.h"
#include "../components/lvgl/lvgl.h"
#include "ui.h"

wifi_ssid_password wifi;

static const char *TAG = "scan";
void time_sync_notification_cb(struct timeval *tv)
{
    ESP_LOGI(TAG, "Notification of a time synchronization event");
}

void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_set_time_sync_notification_cb(time_sync_notification_cb);
#ifdef CONFIG_SNTP_TIME_SYNC_METHOD_SMOOTH
    sntp_set_sync_mode(SNTP_SYNC_MODE_SMOOTH);
#endif
    sntp_init();
}
void obtain_time()
{
    /**
     * NTP server address could be aquired via DHCP,
     * see LWIP_DHCP_GET_NTP_SRV menuconfig option
     */
#ifdef LWIP_DHCP_GET_NTP_SRV
    sntp_servermode_dhcp(1);
#endif
    initialize_sntp();

    // wait for time to be set
    time_t now = 0;
    struct tm timeinfo = {0};
    int retry = 0;
    const int retry_count = 40;
    while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET && ++retry < retry_count)
    {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
    time(&now);

    char strftime_buf[64];
    // Set timezone to China Standard Time
    setenv("TZ", "CST-8", 1);
    tzset();
    localtime_r(&now, &timeinfo);
    ESP_LOGI(TAG, "tm_hour: %i\r\n", timeinfo.tm_hour);
    ESP_LOGI(TAG, "tm_min: %i\r\n", timeinfo.tm_min);
    ESP_LOGI(TAG, "tm_mday: %i\r\n", timeinfo.tm_mday);
    ESP_LOGI(TAG, "tm_mon: %i\r\n", timeinfo.tm_mon + 1);
    ESP_LOGI(TAG, "tm_year: %i\r\n", timeinfo.tm_year + 1900);
    ESP_LOGI(TAG, "tm_wday: %i\r\n", timeinfo.tm_wday);
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    ESP_LOGI(TAG, "The current date/time in Shanghai is: %s", strftime_buf);
}
esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        break;
    }
    return ESP_OK;
}
char *city_task(void)
{
    int8_t return_res = 1;
    char *city_buffer = NULL;
    int content_length = 0;

    esp_http_client_config_t config =
        {
            .event_handler = _http_event_handler,
            .url = "http://whois.pconline.com.cn/ipJson.jsp?ip=xxx.xxx.xxx.xxx&json=true",
        };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    if (client == NULL)
    {
        return NULL;
    }

    // GET Request
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_err_t err = esp_http_client_open(client, 0);
    if (return_res && err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to open HTTP connection: %s", esp_err_to_name(err));
        return_res = 0;
    }
    else
    {
        content_length = esp_http_client_fetch_headers(client);
        if (content_length < 0)
        {
            ESP_LOGE(TAG, "HTTP client fetch headers failed");
            return_res = 0;
        }
        else
        {
            city_buffer = malloc(300);
            memset(city_buffer, 0, 300);
            if (city_buffer == NULL)
            {
                return_res = 0;
            }
            else
            {
                int data_read = esp_http_client_read_response(client, city_buffer, 300);
                if (data_read >= 0)
                {
                    ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d, data_read = %d",
                             esp_http_client_get_status_code(client),
                             esp_http_client_get_content_length(client),
                             data_read);
                    // ESP_LOG_BUFFER_HEX(TAG, city_buffer, data_read);
                    ESP_LOGI(TAG, "Data %s \r\n", city_buffer);
                }
                else
                {
                    return_res = 0;
                    ESP_LOGE(TAG, "Failed to read response");
                }
            }
        }
    }
    esp_http_client_close(client);

    if (return_res == 0)
    {
        free(city_buffer);
        city_buffer = NULL;
    }

    return city_buffer;
}
char *parse_city_json(char *analysis_buf)
{
    char *city_str = NULL;
    if (analysis_buf == NULL)
    {
        return false;
    }

    cJSON *json_root = cJSON_Parse(analysis_buf);
    if (json_root != NULL)
    {
        ESP_LOGI(TAG, "城市[%d] -> %s\r\n", strlen(cJSON_GetObjectItem(json_root, "city")->valuestring) + 1, cJSON_GetObjectItem(json_root, "city")->valuestring);
        city_str = malloc(strlen(cJSON_GetObjectItem(json_root, "city")->valuestring) + 1);
        strcpy(city_str,
               cJSON_GetObjectItem(json_root, "city")->valuestring);
        cJSON_Delete(json_root);
        char *utf8_str = malloc(strlen(city_str) * 2 + 1);
        gb2312ToUtf8(utf8_str, strlen(city_str) * 2 + 1, city_str, strlen(city_str));
        free(city_str);
        city_str = utf8_str;
        ESP_LOGI(TAG, "城市[%s]", city_str);
    }
    free(analysis_buf);

    return city_str;
}
char *xinzhi_task(char *city_str)
{
    int8_t return_res = 1;
    char *weather_buffer = NULL;
    int content_length = 0;

    char city_temp[] = {"http://api.seniverse.com/v3/weather/now.json?key=SWaCmu3LmzT_kS21g&location=                                          &language=zh-Hans&unit=c"};
    char *url_str = utf8_url_encode((const char *)city_str);
    free(city_str);
    sprintf(city_temp, "http://api.seniverse.com/v3/weather/now.json?key=SWaCmu3LmzT_kS21g&location=%s&language=zh-Hans&unit=c", url_str);
    free(url_str);
    ESP_LOGI(TAG, "待打开的url  \r\n%s\r\n", city_temp);
    esp_http_client_config_t config =
        {
            .event_handler = _http_event_handler,
            .url = city_temp,
        };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    if (client == NULL)
    {
        return NULL;
    }

    // GET Request
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_err_t err = esp_http_client_open(client, 0);
    if (return_res && err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to open HTTP connection: %s", esp_err_to_name(err));
        return_res = 0;
    }
    else
    {
        content_length = esp_http_client_fetch_headers(client);
        if (content_length < 0)
        {
            ESP_LOGE(TAG, "HTTP client fetch headers failed");
            return_res = 0;
        }
        else
        {
            weather_buffer = malloc(content_length);
            memset(weather_buffer, 0, content_length);
            if (weather_buffer == NULL)
            {
                return_res = 0;
            }
            else
            {
                int data_read = esp_http_client_read_response(client, weather_buffer, content_length);
                if (data_read >= 0)
                {
                    ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d, data_read = %d",
                             esp_http_client_get_status_code(client),
                             esp_http_client_get_content_length(client),
                             data_read);
                    // ESP_LOG_BUFFER_HEX(TAG, weather_buffer, data_read);
                    ESP_LOGI(TAG, "Data %s \r\n", weather_buffer);
                }
                else
                {
                    ESP_LOGE(TAG, "Failed to read response");
                    return_res = 0;
                }
            }
        }
    }
    esp_http_client_close(client);

    if (!return_res)
    {
        free(weather_buffer);
        weather_buffer = NULL;
    }
    return weather_buffer;
}

bool parse_weather_json(char *analysis_buf)
{
    if (analysis_buf == NULL)
    {
        return false;
    }

    cJSON *json_root = cJSON_Parse(analysis_buf);
    if (json_root != NULL)
    {
        cJSON *cjson_arr = cJSON_GetObjectItem(json_root, "results");
        cJSON *cjson_location = cJSON_GetObjectItem(cJSON_GetArrayItem(cjson_arr, 0), "location");
        ESP_LOGI(TAG, "城市 -> %s\r\n", cJSON_GetObjectItem(cjson_location, "name")->valuestring);
        cJSON *cjson_now = cJSON_GetObjectItem(cJSON_GetArrayItem(cjson_arr, 0), "now");
        ESP_LOGI(TAG, "天气 -> %s\r\n", cJSON_GetObjectItem(cjson_now, "text")->valuestring);
        ESP_LOGI(TAG, "code -> %s\r\n", cJSON_GetObjectItem(cjson_now, "code")->valuestring);
        ESP_LOGI(TAG, "气温 -> %s\r\n", cJSON_GetObjectItem(cjson_now, "temperature")->valuestring);
        // lv_label_set_text_fmt(ui_Label12,"%s",cJSON_GetObjectItem(cjson_location,"name")->valuestring );
        cJSON_Delete(json_root);
    }

    free(analysis_buf);

    return true;
}
void event_handler(void *arg, esp_event_base_t event_base,
                   int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        esp_wifi_connect();
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    { // 连接失败

        // ESP_LOGI(TAG, "WiFi fail\r\n");
        // esp_wifi_connect();
        //printf("ssid :%s password :%s",wifi.ssid,wifi.password);
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    { // 连接成功
        // ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        // ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        // parse_weather_json(xinzhi_task(parse_city_json(city_task())));//天气
        obtain_time(); // 时间
    }
}

/* Initialize Wi-Fi as sta and set scan method */
void fast_scan(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, NULL));
    // ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, IP_EVENT_STA_LOST_IP, &event_handler, NULL, NULL));

    // Initialize default station as network interface instance (esp-netif)
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);
    // Initialize and start WiFi
    wifi_config_t wifi_config = {
        .sta = {
            // .ssid = DEFAULT_SSID,
            // .password = DEFAULT_PWD,
            .scan_method = DEFAULT_SCAN_METHOD,
            .sort_method = DEFAULT_SORT_METHOD,
            .threshold.rssi = DEFAULT_RSSI,
            .threshold.authmode = DEFAULT_AUTHMODE,
        },
    };
    strcpy(wifi_config.sta.ssid,wifi.ssid);
    strcpy(wifi_config.sta.password,wifi.password);
    // printf("ssid :%s pass :%s\r\n",wifi.ssid,wifi.password);
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
}