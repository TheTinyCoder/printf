#ifndef main_h
#define main_h


/**
 * struct printFormat - structure for conversion specifiers
 * @format: flags preceded by %
 * @p: use function of format specified
 */
typedef struct printFormat
{
	char *format;
	int (*p)();
} print_format;


#include <stdarg.h>
int _putchar(char c);

int _printf(const char *format, ...);

/* prints a character */
int print_char(va_list arg);
/* prints a string */
int print_str(va_list arg);

/* prints an integer */
int print_int(va_list arg);
/* prints base 10 */
int print_dec(va_list arg);
#endif
