#include "main.h"

/**
 * print_uint - writes unsigned integer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_uint(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
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
 * uint_recursion - sends each value of unsigned int to array recursively
 * @j: integer
 * @arr: array to hold uint
 * @last_index: last index of uint
 * Return: void
 */

void uint_recursion(unsigned long int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = (j % 10) + 48;
	uint_recursion(j / 10, arr, last_index - 1);
	arr[last_index] = c;
}


/**
 * print_octal - writes octal version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_octal(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
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
 * octal_recursion - sends each octal value of int to array recursively
 * @j: integer
 * @arr: array to hold octal
 * @last_index: last index of array
 * Return: void
 */

void octal_recursion(unsigned long int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = (j % 8) + 48;
	octal_recursion(j / 8, arr, last_index - 1);
	arr[last_index] = c;
}
