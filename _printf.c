#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to string
 * Return: number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int i, (*f)(const char *s), len = 0;
	va_list ptr;

	va_start(ptr, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1), len++, i += 2;
				continue;
			}
			else
				f = get_specifier_func(&format[i + 1]);
			if (f)
			{
				len += f(va_arg(ptr, char *));
			}
		}
		write(1, &format[i], 1), len++;

	}

	va_end(ptr);
	return (len);
}
