#include "main.h"

/**
 * print_long_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_long_hex(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned long int j = va_arg(args, long int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		hex_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_long_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_long_hex_upper(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned long int j = va_arg(args, long int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		hex_upper_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_short_hex(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned short int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		hex_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_short_hex_upper(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned short int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		hex_upper_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}
