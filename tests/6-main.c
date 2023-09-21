#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;
	void *p = (void *)0x7fff5100b608;

	len = _printf("%p\n", p);
	len2 = printf("%p\n", p);

	_printf("%p\n", NULL);
	_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	_printf("");
	_printf("Can you print an address?\n%p\nNice!\n", (void *)-1);
	_printf("%pppp\n", (void *)0x7fff5100b6f8);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
