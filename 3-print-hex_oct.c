#include "main.h"
#include <stdlib.h>

/**
 * fill_hex_array - writes the character c to stdout
 *
 * @binary_array: array where is stored the binary.
 * @hex: array with hexadecimal.
 * @isupper: integer that checks if the hexadecimal array is in uppercase
 * @limit: size of hex
 * Return: binary array.
 */

char *fill_hex_array(char *binary_array, char *hex, int isupper, int limit)
{
	int op, i, j, toletter;

	hex[limit] = '\0';
	if (isupper)
		toletter = 55;
	else
		toletter = 87;
	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((binary_array[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + toletter;
	}
	return (hex);
}


/**
 * print_hex - prints a decimal in hexadecimal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_hex(va_list args, char *buf, unsigned int buf_index)
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
	return (count);
}


/**
 * print_upperhex - prints a decimal in hexadecimal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_upperhex(va_list args, char *buf, unsigned int buf_index)
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
	return (count);
}


/**
 * fill_oct_array - writes the character c to stdout
 * @binary: array with binary.
 * @octal: array with octal.
 * Return: binary array.
 */
char *fill_oct_array(char *binary, char *octal)
{
	int op, i, j, ioct, limit;

	octal[11] = '\0';
	for (i = 31, ioct = 10; i >= 0; i--, ioct--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((binary[i] - '0') * j) + op;
		i++;
		octal[ioct] = op + '0';
	}
	return (octal);
}


/**
 * print_oct - prints decimal number in octal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_oct(va_list args, char *buf, unsigned int buf_index)
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
	return (count);
}
