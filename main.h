#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct specifier_functions - struct that links specifier to function
 * @specifier: pointer to character (can be 'c', 's')
 * @f: pointer to function
 */
typedef struct specifier_functions
{
	char *specifier;
	int (*f)(va_list);
} specifier_funcs;

/* function that returns correct fucntion per specifier */
int (*get_specifier_func(const char *c))(va_list);

/* _printf function */
int _printf(const char *format, ...);

/* print char & string : 'c' & 's' */
int print_char(va_list);
int print_str(va_list);

/* print decimal & integers(other bases to decimal): 'd' & 'i' */
int print_decimal(va_list);
int print_integer(va_list);

/* print binary: 'b' */
int print_binary(va_list args);



/***** UTIL FUNCTIONS ******/

/* integer to string conversion */
char *int_to_str(int);

/* string to integer conversion */
int _atoi(const char *s);

/* hex to decimal conversion */
char *hex_to_decimal(const char *);

/* octal to decimal conversion */
char *octal_to_decimal(const char *);

/* binary to decimal conversion */
char *binary_to_decimal(const char *);

/* hex to binary conversion */
char *hex_to_binary(const char *);

/* octal to binary conversion */
char *octal_to_binary(const char *);

/* decimal to binary conversion */
char *decimal_to_binary(const char *);

#endif

