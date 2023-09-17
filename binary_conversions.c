#include "main.h"

/**
 * hex_to_binary - converts number from hex base to binary
 * @h: number in hex
 * Return: binary number
 */

char *hex_to_binary(const char *h)
{
	char *x = hex_to_decimal(h);

	return (decimal_to_binary(x));
}


/**
 * octal_to_binary - converts number from octal base to binary
 * @o: number in octal
 * Return: binary number
 */

char *octal_to_binary(const char *o)
{
	char *x = octal_to_decimal(o);

	return (decimal_to_binary(x));
}


/**
 * decimal_to_binary - converts number from decimal to binary
 * @d: number in decimal
 * Return: binary number
 */

char *decimal_to_binary(const char *d)
{
	int i = 0, j = _atoi(d), k;
	char *x;

	for (k = j; k > 0; k /= 2)
		i++;
	i += j == 0 ? 1 : 0;
	x = malloc(sizeof(char) * (i + 1));
	if (x)
	{
		x[i] = '\0';
		for (i--; i >= 0; i--)
			x[i] = 48 + (j % 2), j /= 2;
	}
	return (x);
}
