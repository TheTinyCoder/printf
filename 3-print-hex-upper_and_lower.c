#include "main.h"

/**
 * print_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hex(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
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
 * hex_recursion - sends each hex value of int to array recursively
 * @j: integer
 * @arr: array to hold hexadecimal
 * @last_index: last index of array
 * Return: void
 */

void hex_recursion(unsigned int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 97;
	hex_recursion(j / 16, arr, last_index - 1);
	arr[last_index] = c;
}


/**
 * print_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hex_upper(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
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
 * hex_upper_recursion - sends each hex value of int to array recursively
 * @j: integer
 * @arr: array to hold hexadecimal
 * @last_index: last index of array
 * Return: void
 */

void hex_upper_recursion(unsigned int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 65;
	hex_upper_recursion(j / 16, arr, last_index - 1);
	arr[last_index] = c;
}
