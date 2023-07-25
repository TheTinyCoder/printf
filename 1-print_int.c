#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_dec - function entry-point
 *
 * Decription: prints decimal %d
 * @arg: argument to print
 * Return: number of characters printed
 */

int print_dec(va_list arg)
{
	int n = va_arg(arg, int), num, last = n % 10, dig, exp = 1, i = 1;

	n /= 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num *= -1;
		n *= -1;
		last *= -1;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp *= 10;
			num /= 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + 48);
			num -= (dig * exp);
			exp /= 10;
			i++;
		}
	}
	_putchar(last + 48);

	return (i);
}

/**
 * print_int - function entry-point
 *
 * Description: prints integer
 * @arg: argument to print
 * Return: number of characters printed
 */
int print_int(va_list arg)
{
	int n = va_arg(arg, int), num, last = n % 10, dig, exp = 1, i = 1;

	n /= 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num *= -1;
		n *= -1;
		last *= -1;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp *= 10;
			num /= 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + 48);
			num -= (dig * exp);
			exp /= 10;
			i++;
		}
	}
	_putchar(last + 48);

	return (i);
}
