#include "main.h"

/**
 * print_long_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_long_decimal(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	char x = '0', *d = int_to_str(va_arg(args, long int));

	if (d)
	{
		if (_strchr(ptr->flags, '+') && d[0] != '-')
			index = use_buffer(buf, index, '+'), k++;
		else if (_strchr(ptr->flags, ' ') && d[0] != '-')
			index = use_buffer(buf, index, ' '), k++;
		if (_strchr(ptr->flags, '-'))
			left = 1;
		precision = ptr->precision - (_strlen(d) - i);
		if (left == 0 && ptr->period == 0)
		{
			l = ptr->width - (_strlen(d) + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		for (; d[i]; i++)
			index = use_buffer(buf, index, d[i]);
		if (left == 1)
		{
			l = ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		free(d);
		return (i + k);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_long_integer - writes number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_long_integer(va_list args, char *buf, int index, identifierPtr ptr)
{
	int d = 0, j = 0, k = 0, l, left = 0, precision;
	char x = '0', *y = int_to_str(va_arg(args, long int));

	if (y)
	{
		if (_strchr(ptr->flags, '+') && y[0] != '-')
			index = use_buffer(buf, index, '+'), k++;
		else if (_strchr(ptr->flags, ' ') && y[0] != '-')
			index = use_buffer(buf, index, ' '), k++;
		if (_strchr(ptr->flags, '-'))
			left = 1;
		precision = ptr->precision - (_strlen(y) - d);
		if (left == 0 && ptr->period == 0)
		{
			l = ptr->width - (_strlen(y) + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		for (; y[d]; d++)
			index = use_buffer(buf, index, y[d]);
		if (left == 1)
		{
			l = ptr->width - (d + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		free(y);
		return (d + k);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_short_decimal(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	char x = '0', *d = int_to_str((short int)va_arg(args, int));

	if (d)
	{
		if (_strchr(ptr->flags, '+') && d[0] != '-')
			index = use_buffer(buf, index, '+'), k++;
		else if (_strchr(ptr->flags, ' ') && d[0] != '-')
			index = use_buffer(buf, index, ' '), k++;
		if (_strchr(ptr->flags, '-'))
			left = 1;
		precision = ptr->precision - (_strlen(d) - i);
		if (left == 0 && ptr->period == 0)
		{
			l = ptr->width - (_strlen(d) + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		for (; d[i]; i++)
			index = use_buffer(buf, index, d[i]);
		if (left == 1)
		{
			l = ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		free(d);
		return (i + k);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_integer - writes number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_short_integer(va_list args, char *buf, int index, identifierPtr ptr)
{
	int d = 0, j = 0, k = 0, l, left = 0, precision;
	char x = '0', *y = int_to_str((short int)va_arg(args, int));

	if (y)
	{
		if (_strchr(ptr->flags, '+') && y[0] != '-')
			index = use_buffer(buf, index, '+'), k++;
		else if (_strchr(ptr->flags, ' ') && y[0] != '-')
			index = use_buffer(buf, index, ' '), k++;
		if (_strchr(ptr->flags, '-'))
			left = 1;
		precision = ptr->precision - (_strlen(y) - d);
		if (left == 0 && ptr->period == 0)
		{
			l = ptr->width - (_strlen(y) + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				index = use_buffer(buf, index, '0'), k++;
		}
		for (; y[d]; d++)
			index = use_buffer(buf, index, y[d]);
		if (left == 1)
		{
			l = ptr->width - (d + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		}
		free(y);
		return (d + k);
	}
	use_buffer(buf, index, x);
	return (1);
}
