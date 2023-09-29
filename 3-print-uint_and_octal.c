#include "main.h"

/**
 * print_uint - writes unsigned integer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_uint(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	unsigned int n = va_arg(args, int), p;
	char x = '0', *y;
;

	if (n)
	{
		if (_strchr(ptr->flags, '+'))
			index = use_buffer(buf, index, '+'), k++;
		else if (_strchr(ptr->flags, ' '))
			index = use_buffer(buf, index, ' '), k++;
		if (_strchr(ptr->flags, '-'))
			left = 1;
		for (p = n; p > 0; p /= 10)
			i++;
		precision = ptr->precision - i;
		if (left == 0 && ptr->period == 0 && _strchr(ptr->flags, '0'))
		{
			l = ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		y = malloc(sizeof(char) * (i + 1)), y[i] = '\0';
		uint_recursion(n, y, (i - 1));
		for (p = 0; y[p]; p++)
			index = use_buffer(buf, index, y[p]);
		if (left == 1)
		{
			l = ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		} free(y);
		return (i + k);
	} use_buffer(buf, index, x);
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
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_octal(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	unsigned int n = va_arg(args, int), p;
	char x = '0', *y;

	if (n)
	{
		if (_strchr(ptr->flags, '#'))
			index = use_buffer(buf, index, '0'), k++;
		if (_strchr(ptr->flags, '-'))
			left = 1;
		for (p = n; p > 0; p /= 8)
			i++;
		precision = ptr->precision - i;
		if (left == 0 && ptr->period == 0 && _strchr(ptr->flags, '0'))
		{
			l = ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		y = malloc(sizeof(char) * (i + 1)), y[i] = '\0';
		octal_recursion(n, y, (i - 1));
		for (p = 0; y[p]; p++)
			index = use_buffer(buf, index, y[p]);
		if (left == 1)
		{
			l = ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		} free(y);
		return (i + k);
	} use_buffer(buf, index, x);
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
