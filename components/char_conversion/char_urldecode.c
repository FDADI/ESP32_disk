/*
 * @Author: Jinsc
 * @Date: 2022-11-12 22:53:49
 * @LastEditors: Jinsc
 * @LastEditTime: 2022-11-12 22:57:36
 * @FilePath: /fast_scan_xinzhi/components/char_conversion/char_urldecode.c
 * @Description: 
 * Copyright (c) 2022 by jinsc123654@gmail.com All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *utf8_url_decode(const char *input)
{
	int input_length = strlen(input);

	size_t output_length = (input_length + 1) * sizeof(char);
	char *working = malloc(output_length), *output = working;
	
	while(*input)
	{
		if(*input == '%')
		{
			char buffer[3] = { input[1], input[2], 0 };
			*working++ = strtol(buffer, NULL, 16);
			input += 3;
		}
		else
		{
			*working++ = *input++;
		}
	}

	*working = 0; //null terminate
	return output;
}