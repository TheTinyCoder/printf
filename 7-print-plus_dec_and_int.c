#include "main.h"

/**
 * print_decimal_plus - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_decimal_plus(va_list args, char *buf, int index)
{
	int i = 0, j = 0, k = 0;
	char x = '0', *d = int_to_str(va_arg(args, int));

	if (d)
	{
		if (d[0] == 48 && d[1])
		{
			j = d[1] == 'x' || d[1] == 'b' ? 2 : 1;
			for (; d[j]; j++)
				index = use_buffer(buf, index, d[j]), i++;

		}
		else
		{
			if (d[0] != '-')
				index = use_buffer(buf, index, '+'), k++;
			for (; d[i]; i++)
				index = use_buffer(buf, index, d[i]);
		}
		free(d);
		return (i + k);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_integer_plus - writes a number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_integer_plus(va_list args, char *buf, int index)
{
	int d = 0, f = 0;
	char x = '0', *y = int_to_str(va_arg(args, int)), *z;

	if (y)
	{
		if (y[0] == 48 && y[1])
		{
			switch (y[1])
			{
				case 'x':
					z = hex_to_decimal(y);
					break;
				case 'b':
					z = binary_to_decimal(y);
					break;
				default:
					z = octal_to_decimal(y);
			}
			for (; z[d]; d++)
				index = use_buffer(buf, index, z[d]);
			free(z);

		}
		else
		{
			if (y[0] != '-')
				index = use_buffer(buf, index, '+'), f++;
			for (; y[d]; d++)
				index = use_buffer(buf, index, y[d]);
			free(y);
		}
		return (d + f);
	}
	use_buffer(buf, index, x);
	return (1);
}
