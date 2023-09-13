#include "main.h"
#include <stdlib.h>

/**
 * print_lint - prints a long integer
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_lint(va_list args, char *buf, unsigned int buf_index)
{
	long int input;
	unsigned long int in, temp, i, div, neg;

	input = va_arg(args, long int);
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
	{
		buf_index = handle_buf(buf, ((in / div) % 10) + '0', buf_index);
	}
	return (i + neg);
}


/**
 * print_luint - prints a long unsigned integer
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_luint(va_list args, char *buf, unsigned int buf_index)
{
	unsigned long int in, temp, i, div;

	in = va_arg(args, unsigned long int);
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
 * print_shortint - prints a short integer
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_shortint(va_list args, char *buf, unsigned int buf_index)
{
	short int input;
	unsigned short int in, temp, i, div, neg;

	input = va_arg(args, int);
	neg = 0;
	if (input < 0)
	{
		in = input * -1;
		buf_index = handle_buf(buf, '-', buf_index);
		neg = 1;
	}
	else
	{
		in = input;
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
	return (i + neg);
}


/**
 * print_shortuint - prints a short unsigned integer
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_shortuint(va_list args, char *buf, unsigned int buf_index)
{
	unsigned short int in, temp, i, div;

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
