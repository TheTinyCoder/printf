#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: pointer to string
 * Return: number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int i, index = 0, (*f)(va_list, char *, int), len = 0, x;
	va_list args;
	char *buf = malloc(sizeof(char) * BUF_SIZE);

	if (!format || !buf || (format[0] == '%' && !format[1]))
	{
		free(buf);
		return (-1);
	}
	va_start(args, format), index = 0;
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				index = use_buffer(buf, index, format[i]), len++;
			else if (!format[i])
			{
				print_buffer(buf, index), free(buf), va_end(args);
				return (len);
			}
			else
			{
				f = get_specifier_func(&format[i]);
				if (f)
					x = f(args, buf, index), index += x, len += x;
				else
				{
					index = use_buffer(buf, index, format[i - 1]), len++;
					index = use_buffer(buf, index, format[i]), len++;
				}
			}
		}
		else
			index = use_buffer(buf, index, format[i]), len++;
		index = index == BUF_SIZE ? 0 : index;
	}
	print_buffer(buf, index), free(buf), va_end(args);
	return (len);
}
