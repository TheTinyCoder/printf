#include "main.h"

/**
 * print_char - writes a character to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: 1 on success
 */

int print_char(va_list args, char *buf, int index, identifierPtr ptr)
{
	int j = 0, k = 0, left = 0, width;
	char c = va_arg(args, int);

	left = _strchr(ptr->flags, '-') ? 1 : 0;
	width = ptr->width - 1;
	if (left == 0)
		j = print_flags(buf, index, width, ' '), k += j, index += j;
	index = use_buffer(buf, index, c), k++;
	if (left == 1)
		j = print_flags(buf, index, width, ' '), k += j;
	return (k);
}


/**
 * print_str - writes a string to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: length of string
 */

int print_str(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j = 0, k = 0, l, left = 0, min_width, max_width;
	char *x = "(null)", *s = va_arg(args, char *);

	if (s)
	{
		left = _strchr(ptr->flags, '-') ? 1 : 0;
		min_width = ptr->width;
		max_width = ptr->precision;
		l = ptr->period ? min_width - max_width : min_width - _strlen(s);
		if (left == 0)
			j = print_flags(buf, index, l, ' '), k += j, index += j;
		for (; s[i]; i++)
		{
			if (ptr->period && i == max_width)
				break;
			index = use_buffer(buf, index, s[i]);
		}
		if (left == 1)
			j = print_flags(buf, index, l, ' '), k += j;
		return (i + k);
	}
	for (; x[i]; i++)
		index = use_buffer(buf, index, x[i]);
	return (6);
}
