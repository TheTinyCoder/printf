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


/**
 * print_uint - prints an unsigned int
 * @args: argument
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_uint(va_list args, char *buf, unsigned int buf_index)
{
	unsigned int in, temp, i, div;

	in = va_arg(args, unsigned int);
	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		buf_index = handle_buf(buf, ((in / div) % 10) + '0', buf_index);
	}
	return (i);
}


/**
 * print_plusint - print integer with + symbol
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_plusint(va_list args, char *buf, unsigned int buf_index)
{
	int input;
	unsigned int in, temp, i, div;

	input = va_arg(args, int);
	if (input < 0)
	{
		in = input * -1;
		buf_index = handle_buf(buf, '-', buf_index);
	}
	else
	{
		in = input;
		buf_index = handle_buf(buf, '+', buf_index);
	}
	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		buf_index = handle_buf(buf, ((in / div) % 10) + '0', buf_index);
	}
	return (i + 1);
}


/**
 * print_spaceint - prints int begining with space
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed
 */

int print_spaceint(va_list args, char *buf, unsigned int buf_index)
{
	int input;
	unsigned int in, temp, i, div;

	input = va_arg(args, int);
	if (input < 0)
	{
		in = input * -1;
		buf_index = handle_buf(buf, '-', buf_index);
	}
	else
	{
		in = input;
		buf_index = handle_buf(buf, ' ', buf_index);
	}
	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		buf_index = handle_buf(buf, ((in / div) % 10) + '0', buf_index);
	}
	return (i + 1);
}
