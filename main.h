#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>


#define BUF_SIZE 1024

/**
 * identifierPtr - Typedef for struct format_identifiers
 */
typedef struct format_identifiers *identifierPtr;
/**
 * specifierFuncPtr - Typedef for struct specifier_functions
 */
typedef struct specifier_functions *specifierFuncPtr;
/**
 * struct format_identifiers - struct with printf format identifiers
 * @flags: pointer to string with flags i.e. ' ', '+', '#', '-', '0'
 * @width: pointer to minimum field width
 * @period: prefix for precision (1 if it exists, 0 otherwise)
 * @precision: specifies maximum field width for string and float decimal
 * ignore precision if '.' prefix is missing
 * @ptr: pointer to struct that links specifier to function
 * @n: number of characters in identifiers
 */
typedef struct format_identifiers
{
	char *flags;
	int width;
	int period;
	int precision;
	specifierFuncPtr ptr;
	int n;
} identifiers;

/**
 * struct specifier_functions - struct that links specifier to function
 * @specifier: can be 'd', 'i', 'o', 'u', 'x', 'X', 'b', 'c' &
 * 's', 'S' and length modifiers 'l' & 'h' for: 'd','i','o','x','X'
 * @f: pointer to function
 */
typedef struct specifier_functions
{
	char *specifier;
	int (*f)(va_list, char *, int, identifierPtr);
} specifier_funcs;

/* function that gets identifiers from the format string */
identifiers *get_identifiers(va_list, const char *c);

/* function that returns correct fucntion per specifier */
specifier_funcs *get_specifier_func(const char *c);

/* _printf function */
int _printf(const char *format, ...);

/* print char & string : 'c' & 's' */
int print_char(va_list, char *, int, identifierPtr);
int print_str(va_list, char *, int, identifierPtr);

/* print decimal & integers(other bases to decimal): 'd' & 'i' */
int print_decimal(va_list, char *, int, identifierPtr);
int print_integer(va_list, char *, int, identifierPtr);

/* print binary: 'b' */
int print_binary(va_list, char *, int, identifierPtr);
void binary_recursion(unsigned int, char *, int);

/* print unsigned int, octal & hex(lowercase & upper): 'u', 'o', 'x' & 'X' */
int print_uint(va_list, char *, int, identifierPtr);
void uint_recursion(unsigned long int, char *, int);
int print_octal(va_list, char *, int, identifierPtr);
void octal_recursion(unsigned long int, char *, int);
int print_hex(va_list, char *, int, identifierPtr);
void hex_recursion(unsigned long int, char *, int);
int print_hex_upper(va_list, char *, int, identifierPtr);
void hex_upper_recursion(unsigned long int, char *, int);

/* use a local buffer of BUF_SIZE (1024) to reduce calls to write */
int use_buffer(char *buffer, int buffer_index, char c);
void print_buffer(char *buffer, int size);

/* print custom string: 's' */
int print_custom_str(va_list, char *, int, identifierPtr);

/* print an address: 'p' */
int print_address(va_list, char *, int, identifierPtr);
void address_to_hex(unsigned long int, char *, int);

/* print percent: "% %" */
int print_percent(va_list, char *, int, identifierPtr);

/* print long decimal & integers: "ld" & "li" */
int print_long_decimal(va_list, char *, int, identifierPtr);
int print_long_integer(va_list, char *, int, identifierPtr);

/* print short decimal & integers: "hd" & "hi" */
int print_short_decimal(va_list, char *, int, identifierPtr);
int print_short_integer(va_list, char *, int, identifierPtr);

/* print long uint, hex & octal: "lu", "lx", "lX" & "lo" */
int print_long_uint(va_list, char *, int, identifierPtr);
int print_long_hex(va_list, char *, int, identifierPtr);
int print_long_hex_upper(va_list, char *, int, identifierPtr);
int print_long_octal(va_list, char *, int, identifierPtr);

/* print short uint, hex & octal: "hu", "hx", "hX" & "ho" */
int print_short_uint(va_list, char *, int, identifierPtr);
int print_short_hex(va_list, char *, int, identifierPtr);
int print_short_hex_upper(va_list, char *, int, identifierPtr);
int print_short_octal(va_list, char *, int, identifierPtr);



/***** UTIL FUNCTIONS ******/

/* integer to string conversion */
char *int_to_str(long int);

/* compare specifier string to input specifier */
int _strcmp(const char *s1, const char *s2);

/* finds length of string */
int _strlen(char *s);

/* locates character in a string */
int _strchr(char *s, char c);

#endif

