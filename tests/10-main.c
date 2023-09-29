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

	len = _printf("%.6d\n", 102498402);
	len2 = printf("%.6d\n", 102498402);

	_printf("%.6d\n", -102498402);
	_printf("%.6d\n", 0);
	_printf("%.6d\n", 1024);
	_printf("%.6d\n", -1024);
	_printf("In the middle %.6d of a sentence.\n", 1024);
	_printf("%.6i\n", 102498402);
	_printf("%.6i\n", -102498402);
	_printf("%.6i\n", 0);
	_printf("%.6i\n", 1024);
	_printf("%.6i\n", -1024);
	_printf("In the middle %.6i of a sentence.\n", 1024);
	_printf("%.6u\n", 102498402);
	_printf("%.6u\n", -102498402);
	_printf("%.6u\n", 0);
	_printf("%.6u\n", 1024);
	_printf("%.6u\n", -1024);
	_printf("In the middle %.6u of a sentence.\n", 1024);
	_printf("%.6o\n", 102498402);
	_printf("%.6o\n", -102498402);
	_printf("%.6o\n", 0);
	_printf("%.6o\n", 1024);
	_printf("%.6o\n", -1024);
	_printf("In the middle %.6o of a sentence.\n", 1024);
	_printf("%.6x\n", 102498402);
	_printf("%.6x\n", -102498402);
	_printf("%.6x\n", 0);
	_printf("%.6x\n", 1024);
	_printf("%.6x\n", -1024);
	_printf("In the middle %.6x of a sentence.\n", 1024);
	_printf("%.6X\n", 102498402);
	_printf("%.6X\n", -102498402);
	_printf("%.6X\n", 0);
	_printf("%.6X\n", 1024);
	_printf("%.6X\n", -1024);
	_printf("In the middle %.6X of a sentence.\n", 1024);
	_printf("%.6c\n", 'A');
	_printf("In the middle %.6c of a sentence.\n", 'H');
	_printf("%.6s", "Best School !\n");
	_printf("%.6s", "Hi!\n");
	_printf("In the middle %.6s of a sentence.\n", "Hey");
	_printf("%.*d\n", 6, 102498402);
	_printf("%.*d\n", 6, -102498402);
	_printf("%.*d\n", 6, 0);
	_printf("%.*d\n", 6, 1024);
	_printf("%.*d\n", 6, -1024);
	_printf("In the middle %.*d of a sentence.\n", 6, 1024);
	_printf("%.*i\n", 6, 102498402);
	_printf("%.*i\n", 6, -102498402);
	_printf("%.*i\n", 6, 0);
	_printf("%.*i\n", 6, 1024);
	_printf("%.*i\n", 6, -1024);
	_printf("In the middle %.*i of a sentence.\n", 6, 1024);
	_printf("%.*u\n", 6, 102498402);
	_printf("%.*u\n", 6, -102498402);
	_printf("%.*u\n", 6, 0);
	_printf("%.*u\n", 6, 1024);
	_printf("%.*u\n", 6, -1024);
	_printf("In the middle %.*u of a sentence.\n", 6, 1024);
	_printf("%.*o\n", 6, 102498402);
	_printf("%.*o\n", 6, -102498402);
	_printf("%.*o\n", 6, 0);
	_printf("%.*o\n", 6, 1024);
	_printf("%.*o\n", 6, -1024);
	_printf("In the middle %.*o of a sentence.\n", 6, 1024);
	_printf("%.*x\n", 6, 102498402);
	_printf("%.*x\n", 6, -102498402);
	_printf("%.*x\n", 6, 0);
	_printf("%.*x\n", 6, 1024);
	_printf("%.*x\n", 6, -1024);
	_printf("In the middle %.*x of a sentence.\n", 6, 1024);
	_printf("%.*X\n", 6, 102498402);
	_printf("%.*X\n", 6, -102498402);
	_printf("%.*X\n", 6, 0);
	_printf("%.*X\n", 6, 1024);
	_printf("%.*X\n", 6, -1024);
	_printf("In the middle %.*X of a sentence.\n", 6, 1024);
	_printf("%.*c\n", 6, 'A');
	_printf("%.*c\n", 6, 0);
	_printf("In the middle %.*c of a sentence.\n", 6, 'H');
	_printf("%.*s", 6, "Best School !\n");
	_printf("%.*s", 6, "Hi!\n");
	_printf("{%d}", _printf("%.6o", 0));
	printf("(%d)", printf("%.6o", 0));

	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
