#include "main.h"

/**
 * print_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_hex(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned int n = va_arg(args, int), p;
	char *y;

	if (_strchr(ptr->flags, '#'))
	{
		index = use_buffer(buf, index, '0'), k++;
		index = use_buffer(buf, index, 'x'), k++;
	}
	if (_strchr(ptr->flags, '-'))
		left = 1;
	for (p = n; p > 0; p /= 16)
		i++;
	x = i == 0 ? 1 : 0, precision = ptr->precision - i - x;
	if (left == 0 && ptr->period == 0)
	{
		l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	}
	else if (precision > 0)
	{
		for (j = 0; j < precision; j++)
			index = use_buffer(buf, index, '0'), k++;
	}
	y = malloc(sizeof(char) * (i + x + 1)), y[i + x] = '\0';
	if (n)
		hex_recursion(n, y, (i - 1));
	else
		y[0] = 48;
	for (p = 0; y[p]; p++)
		index = use_buffer(buf, index, y[p]);
	if (left == 1)
	{
		l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	} free(y);
	return (i + x + k);
}


/**
 * hex_recursion - sends each hex value of int to array recursively
 * @j: integer
 * @arr: array to hold hexadecimal
 * @last_index: last index of array
 * Return: void
 */

void hex_recursion(unsigned long int j, char *arr, int last_index)
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
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_hex_upper(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned int n = va_arg(args, int), p;
	char *y;

	if (_strchr(ptr->flags, '#'))
	{
		index = use_buffer(buf, index, '0'), k++;
		index = use_buffer(buf, index, 'X'), k++;
	}
	if (_strchr(ptr->flags, '-'))
		left = 1;
	for (p = n; p > 0; p /= 16)
		i++;
	x = i == 0 ? 1 : 0, precision = ptr->precision - i - x;
	if (left == 0 && !ptr->period)
	{
		l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	}
	else if (precision > 0)
	{
		for (j = 0; j < precision; j++)
			index = use_buffer(buf, index, '0'), k++;
	}
	y = malloc(sizeof(char) * (i + x + 1)), y[i + x] = '\0';
	if (n)
		hex_upper_recursion(n, y, (i - 1));
	else
		y[0] = 48;
	for (p = 0; y[p]; p++)
		index = use_buffer(buf, index, y[p]);
	if (left == 1)
	{
		l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	} free(y);
	return (i + x + k);
}


/**
 * hex_upper_recursion - sends each hex value of int to array recursively
 * @j: integer
 * @arr: array to hold hexadecimal
 * @last_index: last index of array
 * Return: void
 */

void hex_upper_recursion(unsigned long int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 65;
	hex_upper_recursion(j / 16, arr, last_index - 1);
	arr[last_index] = c;
}
