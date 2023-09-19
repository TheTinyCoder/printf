#include "main.h"

/**
 * print_char - writes a character to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: 1 on success
 */

int print_char(va_list args, char *buf, int index)
{
	char c = va_arg(args, int);

	use_buffer(buf, index, c);
	return (1);
}


/**
 * print_str - writes a string to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: length of string
 */

int print_str(va_list args, char *buf, int index)
{
	int i = 0;
	char *x = "(null)", *s = va_arg(args, char *);

	if (s)
	{
		for (; s[i]; i++)
			index = use_buffer(buf, index, s[i]);
		return (i);
	}
	for (; x[i]; i++)
		index = use_buffer(buf, index, x[i]);

	return (6);
}

