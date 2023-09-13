#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

/**
 * struct specifiers - struct that links specifier to function
 * @specifier: pointer to character (can be 'c', 's')
 * @f: pointer to function
 */
typedef struct specifier_functions
{
	char *specifier;
	int (*f)(const char *s);
} specifier_funcs;

/* function that returns correct fucntion per specifier */
int (*get_specifier_func(const char *c))(const char *s);

/* _printf function */
int _printf(const char *format, ...);

/* print char & string */
int print_char(const char *c);
int print_str(const char *s);

#endif
