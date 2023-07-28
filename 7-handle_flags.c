#include "main.h"
#include <stdlib.h>

/**
 * print_nhex - print number in hex begining with zero
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */
int print_nhex(va_list args, char *buf, unsigned int buf_index)
{
	int input, i, neg, count, first_digit;
	char *hexadecimal, *binary;

	input = va_arg(args, int);
	neg = 0;
	if (input == 0)
	{
		buf_index = handle_buf(buf, '0', buf_index);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	buf_index = handle_buf(buf, '0', buf_index);
	buf_index = handle_buf(buf, 'x', buf_index);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input, neg, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);
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


/**
 * print_nupperhex - prints number in uppercase hex
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_nupperhex(va_list args, char *buf, unsigned int buf_index)
{
	int input, i, neg, count, first_digit;
	char *hexadecimal, *binary;

	input = va_arg(args, int);
	neg = 0;
	if (input == 0)
	{
		buf_index = handle_buf(buf, '0', buf_index);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	buf_index = handle_buf(buf, '0', buf_index);
	buf_index = handle_buf(buf, 'X', buf_index);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input, neg, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
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


/**
 * print_noct - print the number in octal begining with zero
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_noct(va_list args, char *buf, unsigned int buf_index)
{
	int input, i, neg, count, first_digit;
	char *octal, *binary;

	input = va_arg(args, int);
	neg = 0;
	if (input == 0)
	{
		buf_index = handle_buf(buf, '0', buf_index);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	buf_index = handle_buf(buf, '0', buf_index);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input, neg, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buf_index = handle_buf(buf, octal[i], buf_index);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count + 1);
}
