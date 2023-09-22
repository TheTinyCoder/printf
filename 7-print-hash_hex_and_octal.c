#include "main.h"

/**
 * print_hash_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hash_hex(va_list args, char *buf, int index)
{
	int h = 0, i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		hex_recursion(j, y, (i - 1));
		index = use_buffer(buf, index, '0'), h++;
		index = use_buffer(buf, index, 'x'), h++;
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i + h);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_hash_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hash_hex_upper(va_list args, char *buf, int index)
{
	int h = 0, i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		hex_upper_recursion(j, y, (i - 1));
		index = use_buffer(buf, index, '0'), h++;
		index = use_buffer(buf, index, 'X'), h++;
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i + h);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_hash_octal - writes octal version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hash_octal(va_list args, char *buf, int index)
{
	int h = 0, i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0', *y;

	if (j)
	{
		for (k = j; k > 0; k /= 8)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		index = use_buffer(buf, index, 48), h++;
		octal_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i + h);
	}
	use_buffer(buf, index, x);
	return (1);
}
