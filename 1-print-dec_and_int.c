#include "main.h"

/**
 * print_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_decimal(va_list args, char *buf, int index, identifierPtr ptr)
{
	int h = va_arg(args, int), i = 0, j = 0, k = 0, l, left = 0, precision;
	char *d = int_to_str(h);

	left = _strchr(ptr->flags, '-') ? 1 : 0, j = d[0] == '-' ? 1 : 0;
	k = (_strchr(ptr->flags, '+') || _strchr(ptr->flags, ' '))
		&& h >= 0 ? 1 : 0, precision = ptr->precision - (_strlen(d) - j);
	if (left == 0 && ptr->period == 0 && !_strchr(ptr->flags, 48))
	{
		l = ptr->width - (_strlen(d) + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	}
	if (_strchr(ptr->flags, '+') && d[0] != '-')
		index = use_buffer(buf, index, '+');
	else if (_strchr(ptr->flags, ' ') && d[0] != '-')
		index = use_buffer(buf, index, ' ');
	if (d[0] == '-')
		index = use_buffer(buf, index, d[0]), i++;
	if (left == 0 && ptr->period == 0 && _strchr(ptr->flags, 48))
	{
		l = ptr->width - (_strlen(d) + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, '0'), k++;
	}
	if (precision > 0)
	{
		for (j = 0; j < precision; j++)
			index = use_buffer(buf, index, '0'), k++;
	}
	else if (h == 0 && precision <= 0 && ptr->period)
		return (0);
	for (; d[i]; i++)
		index = use_buffer(buf, index, d[i]);
	if (left == 1)
	{
		l = ptr->width - (i + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	} free(d);
	return (i + k);
}


/**
 * print_integer - writes a number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_integer(va_list args, char *buf, int index, identifierPtr ptr)
{
	int d = 0, h = va_arg(args, int), j = 0, k = 0, l, left = 0, precision;
	char *y = int_to_str(h);

	left = _strchr(ptr->flags, '-') ? 1 : 0, j = y[0] == '-' ? 1 : 0;
	k = (_strchr(ptr->flags, '+') || _strchr(ptr->flags, ' '))
		&& h > 0 ? 1 : 0, precision = ptr->precision - (_strlen(y) - j);
	if (left == 0 && ptr->period == 0 && !_strchr(ptr->flags, 48))
	{
		l = ptr->width - (_strlen(y) + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	}
	if (_strchr(ptr->flags, '+') && y[0] != '-')
		index = use_buffer(buf, index, '+');
	else if (_strchr(ptr->flags, ' ') && y[0] != '-')
		index = use_buffer(buf, index, ' ');
	if (y[0] == '-')
		index = use_buffer(buf, index, y[0]), d++;
	if (left == 0 && ptr->period == 0 && _strchr(ptr->flags, 48))
	{
		l = ptr->width - (_strlen(y) + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, '0'), k++;
	}
	if (precision > 0)
	{
		for (j = 0; j < precision; j++)
			index = use_buffer(buf, index, '0'), k++;
	}
	else if (h == 0 && precision <= 0 && ptr->period)
		return (0);
	for (; y[d]; d++)
		index = use_buffer(buf, index, y[d]);
	if (left == 1)
	{
		l = ptr->width - (d + k);
		for (j = 0; j < l; j++)
			index = use_buffer(buf, index, ' '), k++;
	} free(y);
	return (d + k);
}
