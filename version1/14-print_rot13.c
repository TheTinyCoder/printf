#include "main.h"
#include <stdio.h>

/**
 * print_rot - writes a str in ROT13
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: number of chars printed.
 */

int print_rot(va_list args, char *buf, unsigned int buf_index)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nil[] = "(avyy)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nil[i]; i++)
			buf_index = handle_buf(buf, nil[i], buf_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				buf_index = handle_buf(buf, rot[j], buf_index);
				break;
			}
		}
		if (k == 0)
			buf_index = handle_buf(buf, str[i], buf_index);
	}
	return (i);
}
