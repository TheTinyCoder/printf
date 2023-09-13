#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * print_address - prints the address of input variable
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_address(va_list args, char *buf, unsigned int buf_index)
{
	void *add;
	long int input;
	int i, count, first_digit, neg;
	char *hexadecimal, *binary;
	char nil[] = "(nil)";

	add = (va_arg(args, void *));
	if (add == NULL)
	{
		for (i = 0; nil[i]; i++)
			buf_index = handle_buf(buf, nil[i], buf_index);
		return (5);
	}
	input = (intptr_t)add;
	neg = 0;
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, input, neg, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	buf_index = handle_buf(buf, '0', buf_index);
	buf_index = handle_buf(buf, 'x', buf_index);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buf_index = handle_buf(buf, hexadecimal[i], buf_index);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}
