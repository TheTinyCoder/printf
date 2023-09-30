#include "main.h"

/**
 * print_str_reverse - writes a string in reverse to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: length of string
 */

int print_str_reverse(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j;
	char *x = "(llun)", *s = va_arg(args, char *);

	(void)ptr;
	if (s)
	{
		for (; s[i]; i++)
			;
		for (j = i - 1; j >= 0; j--)
			index = use_buffer(buf, index, s[j]);
		return (i);
	}
	for (; x[i]; i++)
		index = use_buffer(buf, index, x[i]);
	return (6);
}

