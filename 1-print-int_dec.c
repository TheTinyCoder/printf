#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_int - prints an integer
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_int(va_list args, char *buf, unsigned int buf_index)
{
	int input;
	unsigned int in, temp, i, div, neg;

	input = va_arg(args, int);
	neg = 0;
	if (input < 0)
	{
		in = input * -1;
		buf_index = handle_buf(buf, '-', buf_index);
		neg = 1;
	}
	else
		in = input;

	temp = in;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
		buf_index = handle_buf(buf, ((in / div) % 10) + '0', buf_index);
	return (i + neg);
}
