#include "main.h"

/**
 * print_char - writes a character to stdout
 * @args: va_list
 * Return: 1 on success
 */

int print_char(va_list args)
{
	char *c = va_arg(args, char *);

	return (write(1, &c, 1));
}


/**
 * print_str - writes a string to stdout
 * @args: va_list
 * Return: length of string
 */

int print_str(va_list args)
{
	int i = 0;
	char *x = "(null)", *s = va_arg(args, char *);

	if (s)
	{
		for (; s[i]; i++)
			write(1, &s[i], 1);
	}
	else
	{
		for (; x[i]; i++)
			write(1, &x[i], 1);
	}

	return (i);
}

