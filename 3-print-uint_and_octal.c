#include "main.h"

/**
 * print_uint - writes unsigned integer to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_uint(va_list args)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 10)
			i++;
		uint_recursion(j);
		return (i);

	}
	return (write(1, &x, 1));
}


/**
 * uint_recursion - prints each value of unsigned integer recursively
 * @j: integer
 * Return: void
 */

void uint_recursion(unsigned int j)
{
	char c;

	if (j == 0)
		return;

	c = (j % 10) + 48;
	uint_recursion(j / 10);
	write(1, &c, 1);
}


/**
 * print_octal - writes octal version of input to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_octal(va_list args)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 8)
			i++;
		octal_recursion(j);
		return (i);
	}
	return (write(1, &x, 1));
}


/**
 * octal_recursion - prints each octal value of integer recursively
 * @j: integer
 * Return: void
 */

void octal_recursion(unsigned int j)
{
	char c;

	if (j == 0)
		return;

	c = (j % 8) + 48;
	octal_recursion(j / 8);
	write(1, &c, 1);
}
