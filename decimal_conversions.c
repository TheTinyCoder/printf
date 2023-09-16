#include "main.h"

/**
 * hex_to_decimal - converts number from hex base to decimal
 * @h: number in hex
 * Return: decimal number
 */

char *hex_to_decimal(const char *h)
{
	int i = 0, j = 0, k = 1;

	for (; h[i]; i++)
		;
	for (i--; h[i] != 'x'; i--)
		j += (k * h[i]), k *= 16;
	return (int_to_str(j));
}


/**
 * octal_to_decimal - converts number from octal base to decimal
 * @o: number in octal
 * Return: decimal number
 */

char *octal_to_decimal(const char *o)
{
	int i = 0, j = 0, k = 1;

	for (; o[i]; i++)
		;
	for (i--; i > 0; i--)
		j += (k * o[i]), k *= 8;
	return (int_to_str(j));
}


/**
 * binary_to_decimal - converts number from binary to decimal
 * @b: number in binary
 * Return: decimal number
 */

char *binary_to_decimal(const char *b)
{
	int i = 0, j = 0, k = 1;

	for (; b[i]; i++)
		;
	for (i--; b[i] != 'b'; i--)
		j += (k * b[i]), k *= 2;
	return (int_to_str(j));
}
