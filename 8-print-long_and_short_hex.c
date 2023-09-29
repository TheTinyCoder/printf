#include "main.h"

/**
 * print_long_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_long_hex(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	unsigned long int n = va_arg(args, long int), p;
	char x = '0', *y;

	if (n)
	{
		if (_strchr(ptr->flags, '#'))
		{
			index = use_buffer(buf, index, '0'), k++;
			index = use_buffer(buf, index, 'x'), k++;
		}
		if (_strchr(ptr->flags, '-'))
			left = 1;
		for (p = n; p > 0; p /= 16)
			i++;
		precision = ptr->precision - i;
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
		y = malloc(sizeof(char) * (i + 1)), y[i] = '\0';
		hex_recursion(n, y, (i - 1));
		for (p = 0; y[p]; p++)
			index = use_buffer(buf, index, y[p]);
		if (left == 1)
		{
			l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		} free(y);
		return (i + k);
	} use_buffer(buf, index, x);
	return (1);
}


/**
 * print_long_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_long_hex_upper(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	unsigned long int n = va_arg(args, long int), p;
	char x = '0', *y;

	if (n)
	{
		if (_strchr(ptr->flags, '#'))
		{
			index = use_buffer(buf, index, '0'), k++;
			index = use_buffer(buf, index, 'X'), k++;
		}
		if (_strchr(ptr->flags, '-'))
			left = 1;
		for (p = n; p > 0; p /= 16)
			i++;
		precision = ptr->precision - i;
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
		y = malloc(sizeof(char) * (i + 1)), y[i] = '\0';
		hex_upper_recursion(n, y, (i - 1));
		for (p = 0; y[p]; p++)
			index = use_buffer(buf, index, y[p]);
		if (left == 1)
		{
			l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		} free(y);
		return (i + k);
	} use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_short_hex(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	unsigned short int n = va_arg(args, int), p;
	char x = '0', *y;

	if (n)
	{
		if (_strchr(ptr->flags, '#'))
		{
			index = use_buffer(buf, index, '0'), k++;
			index = use_buffer(buf, index, 'x'), k++;
		}
		if (_strchr(ptr->flags, '-'))
			left = 1;
		for (p = n; p > 0; p /= 16)
			i++;
		precision = ptr->precision - i;
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
		y = malloc(sizeof(char) * (i + 1)), y[i] = '\0';
		hex_recursion(n, y, (i - 1));
		for (p = 0; y[p]; p++)
			index = use_buffer(buf, index, y[p]);
		if (left == 1)
		{
			l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
			for (j = 0; j < l; j++)
				index = use_buffer(buf, index, ' '), k++;
		} free(y);
		return (i + k);
	} use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @idx: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_short_hex_upper(va_list args, char *buf, int idx, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, precision;
	unsigned short int n = va_arg(args, int), p;
	char x = '0', *y;

	if (n)
	{
		if (_strchr(ptr->flags, '#'))
		{
			idx = use_buffer(buf, idx, '0'), k++;
			idx = use_buffer(buf, idx, 'X'), k++;
		}
		if (_strchr(ptr->flags, '-'))
			left = 1;
		for (p = n; p > 0; p /= 16)
			i++;
		precision = ptr->precision - i;
		if (left == 0 && ptr->period == 0)
		{
			l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
			for (j = 0; j < l; j++)
				idx = use_buffer(buf, idx, ' '), k++;
		}
		else if (precision > 0)
		{
			for (j = 0; j < precision; j++)
				idx = use_buffer(buf, idx, '0'), k++;
		}
		y = malloc(sizeof(char) * (i + 1)), y[i] = '\0';
		hex_upper_recursion(n, y, (i - 1));
		for (p = 0; y[p]; p++)
			idx = use_buffer(buf, idx, y[p]);
		if (left == 1)
		{
			l = i == 0 ? ptr->width - 1 : ptr->width - (i + k);
			for (j = 0; j < l; j++)
				idx = use_buffer(buf, idx, ' '), k++;
		} free(y);
		return (i + k);
	} use_buffer(buf, idx, x);
	return (1);
}
