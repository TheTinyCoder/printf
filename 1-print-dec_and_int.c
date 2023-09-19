#include "main.h"

/**
 * print_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_decimal(va_list args, char *buf, int index)
{
	int i = 0, j = 0;
	char x = '0', *d = int_to_str(va_arg(args, int));

	if (d)
	{
		if (d[0] == 48 && d[1])
		{
			j = d[1] == 'x' || d[1] == 'b' ? 2 : 1;
			for (; d[j]; j++)
				use_buffer(buf, index, d[j]), i++, index++;

		}
		else
		{
			for (; d[i]; i++)
				use_buffer(buf, index, d[i]), index++;

		}
		free(d);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_integer - writes a number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_integer(va_list args, char *buf, int index)
{
	int d = 0;
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
				use_buffer(buf, index, z[d]), index++;
			free(z);

		}
		else
		{
			for (; y[d]; d++)
				use_buffer(buf, index, y[d]), index++;
			free(y);
		}
		return (d);
	}
	use_buffer(buf, index, x);
	return (1);
}
