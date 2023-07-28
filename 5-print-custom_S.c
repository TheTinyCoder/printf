#include "main.h"
#include <stdlib.h>

/**
 * print_string_S - prints a string and values of non-printed chars
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */
int print_string_S(va_list args, char *buf, unsigned int buf_index)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(args, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buf_index = handle_buf(buf, '\\', buf_index);
			buf_index = handle_buf(buf, 'x', buf_index);
			op = str[i];
			binary = fill_binary_array(binary, op, 0, 32);
			hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
			buf_index = handle_buf(buf, hexadecimal[6], buf_index);
			buf_index = handle_buf(buf, hexadecimal[7], buf_index);
			sum += 3;
		}
		else
			buf_index = handle_buf(buf, str[i], buf_index);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}
