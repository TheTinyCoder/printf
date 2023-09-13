#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: pointer to string
 * Return: number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int i, (*f)(const char *s), len = 0;
	va_list args;

	va_start(args, format);
	if (format)
	{
		for (i = 0; format[i]; i++)
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == '%')
				{
					write(1, &format[i], 1), len++;
					continue;
				}
				else
				{
					f = get_specifier_func(&format[i]);
					if (f)
					{
						len += f(va_arg(args, char *));
						continue;
					}
					else
					{
						len += write(1, &format[i - 1], 1);
						len += write(1, &format[i], 1);
					}
				}
			}
			else
				write(1, &format[i], 1), len++;

		}
	}

	va_end(args);
	return (len);
}
