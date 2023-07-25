#include <main.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - prints a character c
 * @arg: character to print
 * Return: the no. of characters printed (should be 1)
 */

int print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);

	_putchar(c);

	return (1);
}

/**
 * print_str - prints a string s
 * @arg: string to print
 * Return: the no. of characters printed(excluding the null byte)
 */

int print_str(va_list arg)
{
	unsigned int i;
	char *a;

	a = va_arg(arg, char *);

	i = 0;

	if (a == NULL)
		a = "(null)";

	for (; a[i] != '\0'; i++)
		_putchar(a[i]);

	return (i);
}
