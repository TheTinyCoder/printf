#include "main.h"
#include <stdio.h>
/**
 * print_str_rot13 - writes a rot13'ed string to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: length of string
 */

int print_str_rot13(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j, k;
	char *x = "(ahyy)", *s = va_arg(args, char *);

	(void)ptr;
	if (s)
	{
		for (; s[i]; i++)
		{
			if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
				j = s[i] + 13, k = 1;
			else
				j = s[i], k = 0;
			if (j > 90 && s[i] < 91 && k)
				j = (j - 91) + 65;
			else if (j > 122 && s[i] < 123 && k)
				j = (j - 123) + 97;
			index = use_buffer(buf, index, j);
		}
		return (i);
	}
	for (; x[i]; i++)
		index = use_buffer(buf, index, x[i]);
	return (6);
}

