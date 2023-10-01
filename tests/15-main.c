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
	void *ptr = (void *)0x7faf51f0f608;

	len = _printf("%-6s%-6c", "Best", '\n');
	len2 = printf("%-6s%-6c", "Best", '\n');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%-16s%-1c", "Best", '\n');
	len2 = printf("%-16s%-1c", "Best", '\n');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	
	
	len = _printf("%*p\n", 6, ptr);
	len2 = printf("%*p\n", 6, ptr);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*p\n", 26, ptr);
	len2 = printf("%*p\n", 26, ptr);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%-6p\n", (void *)0x7faf51f0f608);
	len2 = printf("%-6p\n", (void *)0x7faf51f0f608);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%.6s", "Best School !\n");
	len2 = printf("%.6s", "Best School !\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	
	len = _printf("%6.6d;%6.6i\n%6.6d;%6.6i\n%6.6d;%6.6i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	len2 = printf("%6.6d;%6.6i\n%6.6d;%6.6i\n%6.6d;%6.6i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.0d;%6.0i\n%6.0d;%6.0i\n%6.0d;%6.0i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	len2 = printf("%6.0d;%6.0i\n%6.0d;%6.0i\n%6.0d;%6.0i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.d;%6.i\n%6.d;%6.i\n%6.d;%6.i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	len2 = printf("%6.d;%6.i\n%6.d;%6.i\n%6.d;%6.i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.6d;%6.6i\n%6.6d;%6.6i\n", 98, 98, -98, -98);
	len2 = printf("%6.6d;%6.6i\n%6.6d;%6.6i\n", 98, 98, -98, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.0d;%6.0i\n%6.0d;%6.0i\n", 98, 98, -98, -98);
	len2 = printf("%6.0d;%6.0i\n%6.0d;%6.0i\n", 98, 98, -98, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.d;%6.i\n%6.d;%6.i\n", 98, 98, -98, -98);
	len2 = printf("%6.d;%6.i\n%6.d;%6.i\n", 98, 98, -98, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	return (0);
}
