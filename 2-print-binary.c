#include "main.h"

/**
 * print_binary - writes binary version of input to stdout
 * @args: va_list
 * Return: number of bytes printed
 */

int print_binary(va_list args)
{
	int i = 0, j = va_arg(args, int), k, neg;
	char w = '-', x = '0', *y, *z;

	neg = j < 0 ? 1 : 0;
	y = neg > 0 ? int_to_str(j * -1) : int_to_str(j);
	if (y)
	{
		if (y[0] == 48 && y[1])
		{
			if (y[1] == 'x')
				z = hex_to_binary(y);
			else if (y[1] == 'b')
				z = y;
			else
				z = octal_to_binary(y);
			if (neg > 0)
				i += write(1, &w, 1);
			for (k = 0; z[k]; k++)
				i += write(1, &z[k], 1);

		}
		else
		{
			z = decimal_to_binary(y);
			if (neg > 0)
				i += write(1, &w, 1);
			for (k = 0; z[k]; k++)
				i += write(1, &z[k], 1);
			free(y);
		}
		free(z);
		return (i);
	}
	return (write(1, &x, 1));
}

