#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - function entry-point
 *
 * Description: produces output according to a format
 * @format: character string
 * Return: number of characters printed excluding null byte
 */


int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, buf_index = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, buf_index), free(buffer), va_end(args);
				return (-1);
			}
			else
			{	function = get_format(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buf(buffer, format[i], buf_index), len++, i--;
				}
				else
				{
					len += function(args, buffer, buf_index);
					i += all_format_functions(format, i + 1);
				}
			} i++;
		}
		else
			handle_buf(buffer, format[i], buf_index), len++;
		for (buf_index = len; buf_index > 1024; buf_index -= 1024)
			;
	}
	print_buf(buffer, buf_index), free(buffer), va_end(args);
	return (len);
}
