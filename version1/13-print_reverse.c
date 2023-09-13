#include "main.h"
#include <stdio.h>
/**
 * print_rev - writes a string in reverse
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */
int print_rev(va_list args, char *buf, unsigned int buf_index)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nil[] = "(llun)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nil[i]; i++)
			buf_index = handle_buf(buf, nil[i], buf_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		buf_index = handle_buf(buf, str[j], buf_index);
	}
	return (i);
}
