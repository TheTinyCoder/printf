#include "main.h"

/**
 * print_long_uint - writes unsigned integer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_long_uint(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned long int n = va_arg(args, long int), p;
	char *y;

	if (_strchr(ptr->flags, '+'))
		index = use_buffer(buf, index, '+'), k++;
	else if (_strchr(ptr->flags, ' '))
		index = use_buffer(buf, index, ' '), k++;
	left = _strchr(ptr->flags, '-') ? 1 : 0;
	for (p = n; p > 0; p /= 10)
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
	else if (n == 0 && precision == 0 && ptr->period)
		return (0);
	y = malloc(sizeof(char) * (i + 1)), y[i + x] = '\0';
	if (n)
		uint_recursion(n, y, (i - 1));
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
 * print_long_octal - writes octal version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_long_octal(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned long int n = va_arg(args, long int), p;
	char *y;

	if (_strchr(ptr->flags, '+'))
		index = use_buffer(buf, index, '+'), k++;
	else if (_strchr(ptr->flags, ' '))
		index = use_buffer(buf, index, ' '), k++;
	left = _strchr(ptr->flags, '-') ? 1 : 0;
	for (p = n; p > 0; p /= 8)
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
	else if (n == 0 && precision == 0 && ptr->period)
		return (0);
	y = malloc(sizeof(char) * (i + 1)), y[i + x] = '\0';
	if (n)
		octal_recursion(n, y, (i - 1));
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
 * print_short_uint - writes unsigned integer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_short_uint(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned short int n = va_arg(args, int), p;
	char *y;

	if (_strchr(ptr->flags, '+'))
		index = use_buffer(buf, index, '+'), k++;
	else if (_strchr(ptr->flags, ' '))
		index = use_buffer(buf, index, ' '), k++;
	left = _strchr(ptr->flags, '-') ? 1 : 0;
	for (p = n; p > 0; p /= 10)
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
	else if (n == 0 && precision == 0 && ptr->period)
		return (0);
	y = malloc(sizeof(char) * (i + 1)), y[i + x] = '\0';
	if (n)
		uint_recursion(n, y, (i - 1));
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
 * print_short_octal - writes octal version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_short_octal(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision, x;
	unsigned short int n = va_arg(args, int), p;
	char *y;


	if (_strchr(ptr->flags, '+'))
		index = use_buffer(buf, index, '+'), k++;
	else if (_strchr(ptr->flags, ' '))
		index = use_buffer(buf, index, ' '), k++;
	left = _strchr(ptr->flags, '-') ? 1 : 0;
	for (p = n; p > 0; p /= 8)
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
	else if (n == 0 && precision == 0 && ptr->period)
		return (0);
	y = malloc(sizeof(char) * (i + 1)), y[i + x] = '\0';
	if (n)
		octal_recursion(n, y, (i - 1));
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

