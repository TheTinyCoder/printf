#include "main.h"
#include <stdio.h>

/**
 * check_conditions - checks if conditions below are met
 * if *format == '%' &&
 * (!format[1] || (_strchr(format[1]) && !format[2]))
 * @s: pointer to string
 * Return: 1 if all are met, 0 otherwise
 */

int check_conditions(const char *s)
{
	char t[] = {' ', '+', 'h', 'l', '#'};

	if (*s == '%')
	{
		if (!s[1])
			return (1);
		if (_strchr(t, s[1]) && !s[2])
			return (1);
	}
	return (0);
}


/**
 * _printf - produces output according to a format
 * @format: pointer to string
 * Return: number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int i, index = 0, len = 0, n = sizeof(char);
	va_list args;
	char *buf = malloc(n * BUF_SIZE), s[] = {' ', '+', 'h', 'l', '#'}, x;
	identifierPtr idPtr;

	if (!format || !buf || check_conditions(format))
	{
		free(buf);
		return (-1);
	} va_start(args, format), index = 0;
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				use_buffer(buf, index, format[i]), len++;
			else
			{
				idPtr = get_identifiers(args, &format[i]), x = format[i];
				if (idPtr && idPtr->ptr)
				{
					len += idPtr->ptr->f(args, buf, index, idPtr);
					i += idPtr->n - 1, free(idPtr->ptr), free(idPtr);
				}
				else if (!_strchr(s, x) || (_strchr(s, x) && format[i + 1]))
				{
					index = use_buffer(buf, index, format[i - 1]), len++;
					if (!_strchr(s, format[i]))
						use_buffer(buf, index, format[i]), len++;
				}
			}
		}
		else
			use_buffer(buf, index, format[i]), len++;
		index = len > BUF_SIZE ? len - BUF_SIZE : len;
	} print_buffer(buf, index), free(buf), va_end(args);
	return (len);
}
