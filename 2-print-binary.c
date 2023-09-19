#include "main.h"

/**
 * print_binary - writes binary version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_binary(va_list args, char *buf, int index)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0';

	if (j)
	{
		for (k = j; k > 0; k /= 2)
			i++;
		binary_recursion(j, buf, (index + i - 1));
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * binary_recursion - prints each binary value of integer recursively
 * @j: integer
 * @buf: buffer
 * @last_index: last index of binary
 * Return: void
 */

void binary_recursion(unsigned int j, char *buf, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = (j % 2) + 48;
	binary_recursion(j / 2, buf, last_index - 1);
	use_buffer(buf, last_index, c);

}
