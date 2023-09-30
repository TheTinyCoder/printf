#include "main.h"
#include <stdio.h>
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
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned int n = va_arg(args, int), p, zero;
	char *y;

	left = _strchr(ptr->flags, '-') ? 1 : 0;
	k = (_strchr(ptr->flags, '+') || _strchr(ptr->flags, ' ')) ? 1 : 0;
	zero = _strchr(ptr->flags, '0') ? 1 : 0;
	for (p = n; p > 0; p /= 10)
		i++;
	x = i == 0 ? 1 : 0, precision = ptr->precision - i - x;
	l = ptr->width - (i + x + k);
	if (left == 0 && ptr->period == 0 && !zero)
		j = print_flags(buf, index, l, ' '), k += j, index += j;
	if (_strchr(ptr->flags, '+'))
		index = use_buffer(buf, index, '+');
	else if (_strchr(ptr->flags, ' '))
		index = use_buffer(buf, index, ' ');
	if (left == 0 && ptr->period == 0 && zero)
		j = print_flags(buf, index, l, '0'), k += j, index += j;
	if (precision > 0)
		j = print_flags(buf, index, precision, '0'), k += j, index += j;
	else if (n == 0 && precision <= 0 && ptr->period)
		return (0);
	y = malloc(sizeof(char) * (i + x + 1)), y[i + x] = '\0', y[0] = 48;
	if (n)
		uint_recursion(n, y, (i - 1));
	for (p = 0; y[p]; p++)
		index = use_buffer(buf, index, y[p]);
	if (left == 1)
		j = print_flags(buf, index, l, ' '), k += j;
	free(y);
	return (i + x + k);
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
	int hash, i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned int n = va_arg(args, int), p, zero;
	char *y;

	left = _strchr(ptr->flags, '-') ? 1 : 0;
	hash = _strchr(ptr->flags, '#') && n ? 1 : 0;
	zero = _strchr(ptr->flags, '0') ? 1 : 0;
	for (p = n; p > 0; p /= 8)
		i++;
	x = i == 0 ? 1 : 0, precision = ptr->precision - i - x;
	l = ptr->width - (i + x + hash);
	if (left == 0 && ptr->period == 0 && !zero)
		j = print_flags(buf, index, l, ' '), k += j, index += j;
	if (hash)
		index = use_buffer(buf, index, '0'), k++;
	if (left == 0 && ptr->period == 0 && zero)
		j = print_flags(buf, index, l, '0'), k += j, index += j;
	if (precision > 0)
		j = print_flags(buf, index, precision, '0'), k += j, index += j;
	else if (n == 0 && precision <= 0 && ptr->period)
		return (0);
	y = malloc(sizeof(char) * (i + x + 1)), y[i + x] = '\0';
	if (n)
		octal_recursion(n, y, (i - 1));
	else
		y[0] = 48;
	for (p = 0; y[p]; p++)
		index = use_buffer(buf, index, y[p]);
	if (left == 1)
		j = print_flags(buf, index, l, ' '), k += j;
	free(y);
	return (i + x + k);
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
