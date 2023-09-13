#include "main.h"
#include <stdlib.h>

/**
 * print_shorthex - prints a short decimal in hexadecimal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_shorthex(va_list args, char *buf, unsigned int buf_index)
{
	short int input, i, neg, count, first_digit;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = fill_binary_array(binary, input, neg, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 4);
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


#include "main.h"
/**
 * print_shortupperhex - prints a short decimal in hexadecimal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */
int print_shortupperhex(va_list args, char *buf, unsigned int buf_index)
{
	short int input, i, neg, count, first_digit;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = fill_binary_array(binary, input, neg, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 1, 4);

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
 * fill_short_oct_array - calculates a short octal number
 *
 * @binary: array where is stored the binary.
 * @octal: array where is stored the octal.
 *
 * Return: binary array.
 */

char *fill_short_oct_array(char *binary, char *octal)
{
	int op, i, j, ioct, limit;

	octal[6] = '\0';
	for (i = 15, ioct = 5; i >= 0; i--, ioct--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((binary[i] - '0') * j) + op;
		i++;
		octal[ioct] = op + '0';
	}
	return (octal);
}


/**
 * print_shortoct - prints long decimal number in octal
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_shortoct(va_list args, char *buf, unsigned int buf_index)
{
	short int input, i, neg, count, first_digit;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = fill_binary_array(binary, input, neg, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = fill_short_oct_array(binary, octal);
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
