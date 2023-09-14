#include "main.h"

/**
 * print_char - writes a character to stdout
 * @c: pointer to character
 * Return: 1 on success
 */

int print_char(const char *c)
{
	return (write(1, &c, 1));
}


/**
 * print_str - writes a string to stdout
 * @s: pointer to string
 * Return: length of string
 */

int print_str(const char *s)
{
	int i = 0;
	char *x = "(null)";

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

