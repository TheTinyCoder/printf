#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%b\n", 1024);
	len2 = _printf("%b\n", 1024);

	_printf("%b\n", -1024);
	_printf("%b\n", 0);
	_printf("%b\n", UINT_MAX);
	_printf("%b\n", UINT_MAX + 1024);
	_printf("There are %b bytes in %b KB\n", 1024, 1);
	_printf("%b - %b = %b\n", 2048, 1024, 1024);
	_printf("%b + %b = %b\n", INT_MAX, INT_MAX);
	_printf("%b\n", 98);



	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
