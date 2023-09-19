#include "main.h"

/**
 * print_hex - writes hex version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hex(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		hex_recursion(j, buf, (index + i - 1));
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * hex_recursion - prints each hex value of integer recursively
 * @j: integer
 * @buf: buffer
 * @last_index: last index of hexadecimal
 * Return: void
 */

void hex_recursion(unsigned int j, char *buf, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 97;
	hex_recursion(j / 16, buf, last_index - 1);
	use_buffer(buf, last_index, c);
}


/**
 * print_hex_upper - writes hex version of input in uppercase to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_hex_upper(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 16)
			i++;
		hex_upper_recursion(j, buf, (index + i - 1));
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * hex_upper_recursion - prints each hex value of integer recursively
 * @j: integer
 * @buf: buffer
 * @last_index: last index of hexadecimal
 * Return: void
 */

void hex_upper_recursion(unsigned int j, char *buf, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = j % 16 < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 65;
	hex_upper_recursion(j / 16, buf, last_index - 1);
	use_buffer(buf, last_index, c);
}
