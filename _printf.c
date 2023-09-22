#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: pointer to string
 * Return: number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int i, index = 0, len = 0;
	va_list args;
	char *buf = malloc(sizeof(char) * BUF_SIZE), *s = "% ";
	specifierFuncPtr funcPtr;

	if (!format || !buf || (*format == '%' && (!format[1] || _strcmp(format, s))))
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
				use_buffer(buf, index, format[i]), len++;
			else if (i == 1 && (format[i] == 'l' || format[i] == 'h') && !format[i + 1])
				len = -1;
			else if (format[i])
			{
				funcPtr = get_specifier_func(&format[i]);
				if (funcPtr)
				{
					len += funcPtr->f(args, buf, index);
					i += _strlen(funcPtr->specifier) - 1, free(funcPtr);
				}
				else if (format[i] != ' ')
				{
					index = use_buffer(buf, index, format[i - 1]), len++;
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
