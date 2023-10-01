#include "main.h"

/**
 * print_address - writes address of a pointer to stdout
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * @ptr: pointer to format identifiers
 * Return: number of bytes printed
 */

int print_address(va_list args, char *buf, int index, identifierPtr ptr)
{
	int i = 0, left, m, n = 0, width;
	unsigned long int j = (uintptr_t)(va_arg(args, void *)), k;
	char *x = "(nil)", *y;

	if (j)
	{
		left = _strchr(ptr->flags, '-') ? 1 : 0;
		for (k = j; k > 0; k /= 16)
			i++;
		width = ptr->width - (i + 2);
		if (left == 0)
			m = print_flags(buf, index, width, ' '), n += m, index += m;
		y = malloc(sizeof(char) * (i + 1 + 2));
		y[i + 2] = '\0';
		y[0] = 48, y[1] = 120;
		address_to_hex(j, y, (i + 1));
		for (k = 0; y[k]; k++)
			index = use_buffer(buf, index, y[k]);
		if (left == 1)
			m = print_flags(buf, index, width, ' '), n += m;
		free(y);
		return (i + n + 2);
	}
	for (; x[i]; i++)
		index = use_buffer(buf, index, x[i]);
	return (5);
}


/**
 * address_to_hex - converts address of a pointer to hex
 * @j: address
 * @arr: array to hold hex
 * @last_index: last index of array
 * Return: void
 */

void address_to_hex(unsigned long int j, char *arr, int last_index)
{
	char c;

	if (j == 0)
		return;
	c = (j % 16) < 10 ? (j % 16) + 48 : ((j % 16) - 10) + 97;
	address_to_hex(j / 16, arr, last_index - 1);
	arr[last_index] = c;
}
