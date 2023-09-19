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
	long int res = INT_MAX;

	len = _printf("%u\n", 1024);
	len2 = printf("%u\n", 1024);

	_printf("%u\n", -1024);
	_printf("%u\n", 0);
	_printf("%u\n", UINT_MAX);
	_printf("%u\n", UINT_MAX + 1024);
	_printf("There are %u bytes in %u KB\n", 1024, 1);
	_printf("%u - %u = %u\n", 2048, 1024, 1024);
	_printf("%u + %u = %u\n", INT_MAX, INT_MAX, (res + res));
	_printf("%o\n", 1024);
	_printf("%o\n", -1024);
	_printf("%o\n", 0);
	_printf("%o\n", UINT_MAX);
	_printf("%o\n", UINT_MAX + 1024);
	_printf("There are %o bytes in %o KB\n", 1024, 1);
	_printf("%o - %o = %o\n", 2048, 1024, 1024);
	_printf("%o + %o = %o\n", INT_MAX, INT_MAX, (res + res));
	_printf("%x\n", 1024);
	_printf("%x\n", -1024);
	_printf("%x\n", 0);
	_printf("%x\n", UINT_MAX);
	_printf("%x\n", UINT_MAX + 1024);
	_printf("There are %x bytes in %x KB\n", 1024, 1);
	_printf("%x - %x = %x\n", 2048, 1024, 1024);
	_printf("%x + %x = %x\n", INT_MAX, INT_MAX, (res + res));
	_printf("%X\n", 1024);
	_printf("%X\n", -1024);
	_printf("%X\n", 0);
	_printf("%X\n", UINT_MAX);
	_printf("%X\n", UINT_MAX + 1024);
	_printf("There are %X bytes in %X KB\n", 1024, 1);
	_printf("%X - %X = %X\n", 2048, 1024, 1024);
	_printf("%X + %X = %X\n", INT_MAX, INT_MAX, (res + res));





	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
