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
	if (*s == '%')
	{
		if (!s[1])
			return (1);
		if (_strchr(s[1]) && !s[2])
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
	int i, index = 0, len = 0;
	va_list args;
	char *buf = malloc(sizeof(char) * BUF_SIZE);
	specifierFuncPtr funcPtr;

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
					funcPtr = get_specifier_func(&format[i]);
				if (funcPtr)
				{
					len += funcPtr->f(args, buf, index);
					i += _strlen(funcPtr->specifier) - 1, free(funcPtr);
				}
				else if (!_strchr(format[i]) || (_strchr(format[i]) && format[i + 1]))
				{
					index = use_buffer(buf, index, format[i - 1]), len++;
					if (!_strchr(format[i]))
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
