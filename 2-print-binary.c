#include "main.h"

/**
 * print_binary - writes binary version of input to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_binary(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0;
	unsigned int j = va_arg(args, int), k;
	char x = '0', *y;

	(void)ptr;
	if (j)
	{
		for (k = j; k > 0; k /= 2)
			i++;
		y = malloc(sizeof(char) * (i + 1));
		y[i] = '\0';
		binary_recursion(j, y, (i - 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		free(y);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * binary_recursion - sends each binary value of int to array recursively
 * @j: integer
 * @arr: array to hold binary
 * @last_index: last index of array
 * Return: void
 */

void binary_recursion(unsigned int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;

	c = (j % 2) + 48;
	binary_recursion(j / 2, arr, last_index - 1);
	arr[last_index] = c;

}
