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

	len = _printf("%06d\n", 102498402);
	len2 = printf("%06d\n", 102498402);

	_printf("%06d\n", -102498402);
	_printf("%06d\n", 0);
	_printf("%06d\n", 1024);
	_printf("%06d\n", -1024);
	_printf("In the middle %06d of a sentence.\n", 1024);
	_printf("%06i\n", 102498402);
	_printf("%06i\n", -102498402);
	_printf("%06i\n", 0);
	_printf("%06i\n", 1024);
	_printf("%06i\n", -1024);
	_printf("In the middle %06i of a sentence.\n", 1024);
	_printf("%06u\n", 102498402);
	_printf("%06u\n", -102498402);
	_printf("%06u\n", 0);
	_printf("%06u\n", 1024);
	_printf("%06u\n", -1024);
	_printf("In the middle %06u of a sentence.\n", 1024);
	_printf("%06o\n", 102498402);
	_printf("%06o\n", -102498402);
	_printf("%06o\n", 0);
	_printf("%06o\n", 1024);
	_printf("%06o\n", -1024);
	_printf("In the middle %06o of a sentence.\n", 1024);
	_printf("%06x\n", 102498402);
	_printf("%06x\n", -102498402);
	_printf("%06x\n", 0);
	_printf("%06x\n", 1024);
	_printf("%06x\n", -1024);
	_printf("In the middle %06x of a sentence.\n", 1024);
	_printf("%06X\n", 102498402);
	_printf("%06X\n", -102498402);
	_printf("%06X\n", 0);
	_printf("%06X\n", 1024);
	_printf("%06X\n", -1024);
	_printf("In the middle %06X of a sentence.\n", 1024);
	_printf("%06c\n", 'A');
	_printf("In the middle %06c of a sentence.\n", 'H');
	_printf("%06s", "Best School !\n");
	_printf("%06s", "Hi!\n");
	_printf("In the middle %06s of a sentence.\n", "Hey");
	_printf("%0*d\n", 6, 102498402);
	_printf("%0*d\n", 6, -102498402);
	_printf("%0*d\n", 6, 0);
	_printf("%0*d\n", 6, 1024);
	_printf("%0*d\n", 6, -1024);
	_printf("In the middle %0*d of a sentence.\n", 6, 1024);
	_printf("%0*i\n", 6, 102498402);
	_printf("%0*i\n", 6, -102498402);
	_printf("%0*i\n", 6, 0);
	_printf("%0*i\n", 6, 1024);
	_printf("%0*i\n", 6, -1024);
	_printf("In the middle %0*i of a sentence.\n", 6, 1024);
	_printf("%0*u\n", 6, 102498402);
	_printf("%0*u\n", 6, -102498402);
	_printf("%0*u\n", 6, 0);
	_printf("%0*u\n", 6, 1024);
	_printf("%0*u\n", 6, -1024);
	_printf("In the middle %0*u of a sentence.\n", 6, 1024);
	_printf("%0*o\n", 6, 102498402);
	_printf("%0*o\n", 6, -102498402);
	_printf("%0*o\n", 6, 0);
	_printf("%0*o\n", 6, 1024);
	_printf("%0*o\n", 6, -1024);
	_printf("In the middle %0*o of a sentence.\n", 6, 1024);
	_printf("%0*x\n", 6, 102498402);
	_printf("%0*x\n", 6, -102498402);
	_printf("%0*x\n", 6, 0);
	_printf("%0*x\n", 6, 1024);
	_printf("%0*x\n", 6, -1024);
	_printf("In the middle %0*x of a sentence.\n", 6, 1024);
	_printf("%0*X\n", 6, 102498402);
	_printf("%0*X\n", 6, -102498402);
	_printf("%0*X\n", 6, 0);
	_printf("%0*X\n", 6, 1024);
	_printf("%0*X\n", 6, -1024);
	_printf("In the middle %0*X of a sentence.\n", 6, 1024);
	_printf("%0*c\n", 6, 'A');
	_printf("%0*c\n", 6, 0);
	_printf("In the middle %0*c of a sentence.\n", 6, 'H');
	_printf("%0*s", 6, "Best School !\n");
	_printf("%0*s", 6, "Hi!\n");
		
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
