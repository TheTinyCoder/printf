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

	len = _printf("%ld\n", 1024L);
	len2 = printf("%ld\n", 1024L);

	_printf("%ld\n", -1024L);
	_printf("%ld\n", 0L);
	_printf("%ld\n", LONG_MAX);
	_printf("%ld\n", LONG_MIN);
	_printf("There are %ld bytes in %ld KB\n", 1024L, 1L);
	_printf("%ld - %ld = %ld\n", 1024L, 2048L, -1024L);
	_printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	_printf("%li\n", 1024L);
	_printf("%li\n", -1024L);
	_printf("%li\n", 0L);
	_printf("%li\n", LONG_MAX);
	_printf("%li\n", LONG_MIN);
	_printf("There are %li bytes in %li KB\n", 1024L, 1L);
	_printf("%li - %li = %li\n", 1024L, 2048L, -1024L);
	_printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	_printf("%lu\n", 1024UL);
	_printf("%lu\n", 0L);
	_printf("%lu\n", ULONG_MAX);
	_printf("There are %lu bytes in %lu KB\n", 1024UL, 1UL);
	_printf("%lu - %lu = %lu\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	
	_printf("%lo\n", 1024UL);
	_printf("%lo\n", 0UL);
	_printf("%lo\n", ULONG_MAX);
	_printf("There are %lo bytes in %lo KB\n", 1024UL, 1UL);
	_printf("%lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	
	_printf("%lx\n", 1024UL);
	_printf("%lx\n", 0UL);
	_printf("%lx\n", ULONG_MAX);
	_printf("There are %lx bytes in %lx KB\n", 1024UL, 1UL);
	_printf("%lx - %lx = %lx\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	
	_printf("%lX\n", 1024UL);
	_printf("%lX\n", 0UL);
	_printf("%lX\n", ULONG_MAX);
	_printf("There are %lX bytes in %lX KB\n", 1024UL, 1UL);
	_printf("%lX - %lX = %lX\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	
	_printf("%hd\n", 1024);
	_printf("%hd\n", -1024);
	_printf("%hd\n", 0);
	_printf("%hd\n", SHRT_MAX);
	_printf("%hd\n", SHRT_MIN);
	_printf("There are %hd bytes in %hd KB\n", 1024, 1);
	_printf("%hd - %hd = %hd\n", 1024, 2048, -1024);
	_printf("%hd + %hd = %hd\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	_printf("%hi\n", 1024);
	_printf("%hi\n", -1024);
	_printf("%hi\n", 0);
	_printf("%hi\n", SHRT_MAX);
	_printf("%hi\n", SHRT_MIN);
	_printf("There are %hi bytes in %hi KB\n", 1024, 1);
	_printf("%hi - %hi = %hi\n", 1024, 2048, -1024);
	_printf("%hi + %hi = %hi\n", SHRT_MIN, SHRT_MAX, (SHRT_MIN + SHRT_MAX));
	_printf("%hu\n", 1024);
	_printf("%hu\n", 0);
	_printf("%hu\n", USHRT_MAX);
	_printf("There are %hu bytes in %hu KB\n", 1024, 1);
	_printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	
	_printf("%ho\n", 1024);
	_printf("%ho\n", 0);
	_printf("%ho\n", USHRT_MAX);
	_printf("There are %ho bytes in %ho KB\n", 1024, 1);
	_printf("%ho - %ho = %ho\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	
	_printf("%hx\n", 1024);
	_printf("%hx\n", 0);
	_printf("%hx\n", USHRT_MAX);
	_printf("There are %hx bytes in %hx KB\n", 1024, 1);
	_printf("%hx - %hx = %hx\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	
	_printf("%hX\n", 1024);
	_printf("%hX\n", 0);
	_printf("%hX\n", USHRT_MAX);
	_printf("There are %hX bytes in %hX KB\n", 1024, 1);
	_printf("%hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	_printf("%h\n");
	_printf("%l\n");




	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
