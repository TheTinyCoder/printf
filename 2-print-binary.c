#include "main.h"

/**
 * print_binary - writes binary version of input to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_binary(va_list args)
{
	int neg;
	long int j = va_arg(args, long int);
	char x = '0';

	neg = j < 0 ? 1 : 0;
	j = neg > 0 ? UINT_MAX + j : j;
	if (j)
		return (binary_recursion(j, 0));
	return (write(1, &x, 1));
}


/**
 * binary_recursion - prints each binary value of integer recursively
 * @j: integer
 * @count: bytes
 * Return: number of bytes printed
 */

int binary_recursion(long int j, int count)
{
	char c;

	if (j == 0)
		return (count);

	c = (j % 2) + 48;
	count += binary_recursion((j / 2), count + 1);
	write(1, &c, 1);
	return (count);
}
