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

	len = _printf("%d\n", 1024);
	len2 = printf("%d\n", 1024);

	_printf("%d\n", -1024);
	_printf("%d\n", 0);
	_printf("%d\n", INT_MAX);
	_printf("%d\n", INT_MIN);
	_printf("There are %d bytes in %d KB\n", 1024, 1);
	_printf("%d - %d = %d\n", 1024, 2048, -1024);
	_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	_printf("%i\n", 1024);
	_printf("%i\n", -1024);
	_printf("%i\n", 0);
	_printf("%i\n", INT_MAX);
	_printf("%i\n", INT_MIN);
	_printf("There are %i bytes in %i KB\n", 1024, 1);
	_printf("%i - %i = %i\n", 1024, 2048, -1024);
	_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	_printf("%d == %i\n", 1024, 1024);
	_printf("iddi%diddiiddi\n", 1024);
	_printf("%d\n", 10000);
	_printf("%i\n", 10000);



	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
