#include "main.h"

/**
 * print_binary - writes binary version of input to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_binary(va_list args)
{
	int i = 0, neg;
	long int j = va_arg(args, long int), k;
	char x = '0';

	neg = j < 0 ? 1 : 0;
	j = neg > 0 ? UINT_MAX + j : j;
	if (j)
	{
		for (k = j; k > 0; k /= 2)
			i++;
		binary_recursion(j);
		return (i);
	}
	return (write(1, &x, 1));
}


/**
 * binary_recursion - prints each binary value of integer recursively
 * @j: integer
 * Return: void
 */

void binary_recursion(long int j)
{
	char c;

	if (j == 0)
		return;

	c = (j % 2) + 48;
	binary_recursion(j / 2);
	write(1, &c, 1);
}
