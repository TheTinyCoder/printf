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

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (!format[0])
		return (len);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				write(1, &format[i], 1), len++;
			else if (!format[i])
			{
				va_end(args);
				return (len);
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
					len += !format[i] ? 0 : write(1, &format[i - 1], 1);
					len += write(1, &format[i], 1);
				}
			}
		}
		else
			write(1, &format[i], 1), len++;
	}
	va_end(args);
	return (len);
}
