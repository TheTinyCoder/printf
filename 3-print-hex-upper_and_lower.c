#include "main.h"

/**
 * print_hex - writes hex version of input to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_hex(va_list args)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		hex_recursion(j);
		return (i);
	}
	return (write(1, &x, 1));
}


/**
 * hex_recursion - prints each hex value of integer recursively
 * @j: integer
 * Return: void
 */

void hex_recursion(unsigned int j)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 97;

	hex_recursion(j / 16);
	write(1, &c, 1);
}


/**
 * print_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_hex_upper(va_list args)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		hex_upper_recursion(j);
		return (i);
	}
	return (write(1, &x, 1));
}


/**
 * hex_upper_recursion - prints each hex value of integer recursively
 * @j: integer
 * Return: void
 */

void hex_upper_recursion(unsigned int j)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 65;
	hex_upper_recursion(j / 16);
	write(1, &c, 1);
}
