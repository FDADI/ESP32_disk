file(GLOB_RECURSE SOURCES 	./*.c 
							)

idf_component_register(SRCS	${SOURCES}
                   INCLUDE_DIRS 
								.
                    REQUIRES nvs_flash esp_http_client char_conversion json lvgl ui_code) 
