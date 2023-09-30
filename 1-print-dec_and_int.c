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

	left = _strchr(ptr->flags, '-') ? 1 : 0;
	j = d[0] == '-' ? 1 : 0;
	k = (_strchr(ptr->flags, '+') || _strchr(ptr->flags, ' '))
		&& h >= 0 ? 1 : 0;
	precision = ptr->precision - (_strlen(d) - j);
	l = ptr->width - (_strlen(d) + k);
	if (left == 0 && ptr->period == 0 && !_strchr(ptr->flags, 48))
		j = print_flags(buf, index, l, ' '), k += j, index += j;
	if (_strchr(ptr->flags, '+') && d[0] != '-')
		index = use_buffer(buf, index, '+');
	else if (_strchr(ptr->flags, ' ') && d[0] != '-')
		index = use_buffer(buf, index, ' ');
	if (d[0] == '-')
		index = use_buffer(buf, index, d[0]), i++;
	if (left == 0 && ptr->period == 0 && _strchr(ptr->flags, 48))
		j = print_flags(buf, index, l, '0'), k += j, index += j;
	if (precision > 0)
		j = print_flags(buf, index, precision, '0'), k += j, index += j;
	else if (h == 0 && precision <= 0 && ptr->period)
		return (0);
	for (; d[i]; i++)
		index = use_buffer(buf, index, d[i]);
	if (left == 1)
		j = print_flags(buf, index, l, ' '), k += j;
	free(d);
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

	left = _strchr(ptr->flags, '-') ? 1 : 0;
	j = y[0] == '-' ? 1 : 0;
	k = (_strchr(ptr->flags, '+') || _strchr(ptr->flags, ' '))
		&& h >= 0 ? 1 : 0;
	precision = ptr->precision - (_strlen(y) - j);
	l = ptr->width - (_strlen(y) + k);
	if (left == 0 && ptr->period == 0 && !_strchr(ptr->flags, 48))
		j = print_flags(buf, index, l, ' '), k += j, index += j;
	if (_strchr(ptr->flags, '+') && y[0] != '-')
		index = use_buffer(buf, index, '+');
	else if (_strchr(ptr->flags, ' ') && y[0] != '-')
		index = use_buffer(buf, index, ' ');
	if (y[0] == '-')
		index = use_buffer(buf, index, y[0]), d++;
	if (left == 0 && ptr->period == 0 && _strchr(ptr->flags, 48))
		j = print_flags(buf, index, l, '0'), k += j, index += j;
	if (precision > 0)
		j = print_flags(buf, index, precision, '0'), k += j, index += j;
	else if (h == 0 && precision <= 0 && ptr->period)
		return (0);
	for (; y[d]; d++)
		index = use_buffer(buf, index, y[d]);
	if (left == 1)
		j = print_flags(buf, index, l, ' '), k += j;
	free(y);
	return (d + k);
}
