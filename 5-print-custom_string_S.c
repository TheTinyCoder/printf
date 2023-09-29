#include "main.h"

/**
 * print_custom_str - writes a special string to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_custom_str(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, j, k = 0;
	char *x = "(null)", *s = va_arg(args, char *), y[2];

	(void)ptr;
	if (s)
	{
		for (; s[i]; i++)
		{
			j = s[i];
			if (j >= 32 && j < 127)
				index = use_buffer(buf, index, s[i]);
			else
			{
				index = use_buffer(buf, index, 92);
				index = use_buffer(buf, index, 120), k++;
				y[1] = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 65, j /= 16;
				y[0] = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 65;
				index = use_buffer(buf, index, y[0]), k++;
				index = use_buffer(buf, index, y[1]), k++;
			}
		}
		return (i + k);
	}
	for (; x[i]; i++)
		index = use_buffer(buf, index, x[i]);

	return (6);
}

