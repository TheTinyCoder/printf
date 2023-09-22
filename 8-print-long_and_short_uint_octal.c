#include "main.h"

/**
 * print_long_uint - writes unsigned integer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_long_uint(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned long int j = va_arg(args, long int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 10)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		uint_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);

	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_long_octal - writes octal version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_long_octal(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned long int j = va_arg(args, long int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 8)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		octal_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_uint - writes unsigned integer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_short_uint(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned short int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 10)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		uint_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);

	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_octal - writes octal version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_short_octal(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned short int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 8)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		octal_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}

