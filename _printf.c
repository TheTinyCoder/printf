#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - function entry-point
 *
 * Description: produces output according to a format
 * @format: character string
 * Return: number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int flag, i, j, len = 0;

	print_format print[] = {
		{"c", print_char}, {"s", print_str},
		{NULL, NULL}
	};

	va_start(arg, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		va_end(arg);
		return (0);
	}

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j = 0;
			flag = 0;
			while (print[j].p != NULL)
			{
				if (format[i + 1] == print[j].format[0])
				{
					len += print[j].p(arg);
					flag = 1;
					i++;
				}
				j++;
			}
			if (flag == 0)
			{
				_putchar(format[i]);
				len = len + 1;
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i++;
			len = len + 1;
		}
		else
		{
			_putchar(format[i]);
			len = len + 1;
		}
		i++;
	}
	va_end(arg);

	return (len);
}
