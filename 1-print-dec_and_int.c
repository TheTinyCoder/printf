#include "main.h"

/**
 * print_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * Return: number of bytes printed
 */

int print_decimal(va_list args)
{
	int i = 0, j = 0;
	char x = '0', *d = int_to_str(va_arg(args, int));

	if (d)
	{
		if (d[0] == 48 && d[1])
		{
			j = d[1] == 'x' || d[1] == 'b' ? 2 : 1;
			for (; d[j]; j++)
				i += write(1, &d[j], 1);

		}
		else
		{
			for (; d[i]; i++)
				write(1, &d[i], 1);
		}
		return (i);
	}
	return (write(1, &x, 1));
}


/**
 * print_integer - writes a number to stdout after converting to decimal
 * @args: va_list
 * Return: number of bytes printed
 */

int print_integer(va_list args)
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
				write(1, &z, 1);
			free(z);

		}
		else
		{
			for (; y[d]; d++)
				write(1, &y[d], 1);
		}
		return (d);
	}
	return (write(1, &x, 1));
}
