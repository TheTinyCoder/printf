#include "main.h"
#include <stdlib.h>

/**
 * print_lhex - prints a long decimal in hexadecimal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_lhex(va_list args, char *buf, unsigned int buf_index)
{
	long int input, i, neg, count, first_digit;
	char *hexadecimal, *binary;

	input = va_arg(args, long int);
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, input, neg, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
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
 * print_lupperhex - prints a long decimal in hexadecimal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_lupperhex(va_list args, char *buf, unsigned int buf_index)
{
	long int input, i, neg, count, first_digit;
	char *hexadecimal, *binary;

	input = va_arg(args, long int);
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, input, neg, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 1, 16);
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
 * fill_long_oct_array - calculates a long octal number
 *
 * @binary: array with binary.
 * @oct: array with octal.
 * Return: binary array.
 */

char *fill_long_oct_array(char *binary, char *oct)
{
	int op, i, j, ioct, limit;

	oct[22] = '\0';
	for (i = 63, ioct = 21; i >= 0; i--, ioct--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((binary[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}


/**
 * print_loct - prints long decimal number in octal
 * @args: arguments
 * @buf: buffer pointer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_loct(va_list args, char *buf, unsigned int buf_index)
{
	long int input, i, neg, count, first_digit;
	char *octal, *binary;

	input = va_arg(args, long int);
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, input, neg, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = fill_long_oct_array(binary, octal);
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
