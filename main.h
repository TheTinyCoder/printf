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




/***** UTIL FUNCTIONS ******/

/* integer to (char *) conversion */
char *int_to_str(int);

/* hex to decimal conversion */
char *hex_to_decimal(const char *);

/* octal to decimal conversion */
char *octal_to_decimal(const char *);

/* hex to decimal conversion */
char *binary_to_decimal(const char *);

#endif

