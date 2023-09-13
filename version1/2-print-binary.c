#include "main.h"
#include <stdlib.h>


/**
 * fill_binary_array - prints decimal in binary
 * @binary: pointer to binary
 * @in: input number
 * @neg: 0 if positive, 1 if negative
 * @limit: size of the binary
 * Return: number of chars printed.
 */

char *fill_binary_array(char *binary, long int in, int neg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary[i] = '0';
	binary[limit] = '\0';
	for (i = limit - 1; in > 1; i--)
	{
		if (in == 2)
			binary[i] = '0';
		else
			binary[i] = (in % 2) + '0';
		in /= 2;
	}
	if (in != 0)
		binary[i] = '1';
	if (neg)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}


/**
 * print_binary - prints decimal in binary
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_binary(va_list args, char *buf, unsigned int buf_index)
{
	int input, count, i, first_one, neg;
	char *binary;

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
	first_one = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			buf_index = handle_buf(buf, binary[i], buf_index);
			count++;
		}
	}
	free(binary);
	return (count);
}
