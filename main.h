#ifndef main_h
#define main_h
#include <stdarg.h>


/**
 * struct printFormat - structure for conversion specifiers
 * @format: flags preceded by %
 * @p: use function of format specified
 */
typedef struct printFormat
{
	char *format;
	int (*f)(va_list, char *, unsigned int);
} print_format;


int _putchar(char c);

int _printf(const char *format, ...);

/* prints a character */
int print_char(va_list args, char *buf, unsigned int buf_index);
/* prints a string */
int print_str(va_list args, char *buf, unsigned int buf_index);

/* prints an integer */
int print_int(va_list args, char *buf, unsigned int buf_index);
/* prints an integer in base 10 */
int print_dec(va_list args);

/* util functions */
int (*get_format_func(const char *s, int index))(va_list, char *, unsigned int);
int all_format_functions(const char *s, int index);
unsigned int handle_buf(char *buf, char c, unsigned int buf_index);
int print_buf(char *buf, unsigned int buf_index);
#endif
