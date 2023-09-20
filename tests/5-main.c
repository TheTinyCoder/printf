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

	len = _printf("%S", "\n");
	_printf("\n");
	len2 = printf("\\x0A");
	printf("\n");

	_printf("\n");
	_printf("%S", "No special character.");
	_printf("\n");
	_printf("%S", "\x01\x02\x03\x04\x05\x06\x07");
	_printf("\n");
	_printf("Could you print some non-printable characters?\n%S\nThanks!\n", "Sure:\x1F\x7F\n");
	_printf("\n");
	_printf("");
	_printf("\n");
	_printf("- What did you say?\n- %S\n- That's what I thought.\n", "");
	_printf("\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
