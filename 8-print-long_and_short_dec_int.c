#include "main.h"

/**
 * print_long_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_long_decimal(va_list args, char *buf, int index)
{
	int i = 0, j = 0;
	char x = '0', *d = int_to_str(va_arg(args, long int));

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
			for (; d[i]; i++)
				index = use_buffer(buf, index, d[i]);

		}
		free(d);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_long_integer - writes number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_long_integer(va_list args, char *buf, int index)
{
	int d = 0;
	char x = '0', *y = int_to_str(va_arg(args, long int)), *z;

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
			for (; y[d]; d++)
				index = use_buffer(buf, index, y[d]);
			free(y);
		}
		return (d);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_decimal - writes a number to stdout assuming base 10
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_short_decimal(va_list args, char *buf, int index)
{
	int i = 0, j = 0;
	char x = '0', *d = int_to_str((short int)va_arg(args, int));

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
			for (; d[i]; i++)
				index = use_buffer(buf, index, d[i]);

		}
		free(d);
		return (i);
	}
	use_buffer(buf, index, x);
	return (1);
}


/**
 * print_short_integer - writes number to stdout after converting to decimal
 * @args: va_list
 * @buf: buffer
 * @index: buffer index
 * Return: number of bytes printed
 */

int print_short_integer(va_list args, char *buf, int index)
{
	int d = 0;
	char x = '0', *y = int_to_str((short int)va_arg(args, int)), *z;

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
			for (; y[d]; d++)
				index = use_buffer(buf, index, y[d]);
			free(y);
		}
		return (d);
	}
	use_buffer(buf, index, x);
	return (1);
}
