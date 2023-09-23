/*
 * @Author: Jinsc
 * @Date: 2022-11-12 22:53:49
 * @LastEditors: Jinsc
 * @LastEditTime: 2022-11-12 22:55:42
 * @FilePath: /fast_scan_xinzhi/components/char_conversion/char_urlencode.c
 * @Description: 
 * Copyright (c) 2022 by jinsc123654@gmail.com All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//two ways to use urlencode:
// urlencode stuff
// echo stuff | urlencode 

//note unicode support should happen upstream of this.
bool is_non_symbol(char c)
{
    if(c == '\0') return 1; //we want to write null regardless
    int c_int = (int)c;
    return (c_int >= 48 && c_int <= 57) || (c_int >= 65 && c_int <= 90) || (c_int >= 97 && c_int <= 122);
}

char *utf8_url_encode(const char *input)
{
    int end = strlen(input);
    size_t final_size = (end * 3) + 1;
    char *working = malloc(final_size * sizeof(char)), *output = working;

    while(*input)
    {
        const char c = *input;
        if(c < 0)
        {
            input++;
        }
        else if(is_non_symbol(c)) 
        {
            *working++ = *input++;
        }
        else
        {
            char encoded[4] = {0};
            snprintf(encoded, 4, "%%%02x", c);

            *working++ = encoded[0];
            *working++ = encoded[1];
            *working++ = encoded[2];
            input++;
        }
    }

    *working = 0; //null term
    return output;
}