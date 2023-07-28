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

/* prints a percentage */
int print_percent(va_list __attribute__((unused)), char *, unsigned int);

/* prints a string */
int print_str(va_list args, char *buf, unsigned int buf_index);

/* prints a string with custom specifier S */
int print_string_S(va_list args, char *buf, unsigned int buf_index);

/* prints an integer */
int print_int(va_list args, char *buf, unsigned int buf_index);

/* prints an integer in base 10 */
int print_dec(va_list args);

/* prints unsigned integer */
int print_uint(va_list args, char *buf, unsigned int buf_index);

/* prints an integer as hex */
int print_hex(va_list args, char *buf, unsigned int buf_index);
int print_upperhex(va_list args, char *buf, unsigned int buf_index);

/* prints an integer as octal */
int print_oct(va_list args, char *buf, unsigned int buf_index);

/* prints an address */
int print_address(va_list args, char *buf, unsigned int buf_index);

/* handles flags */
int print_plusint(va_list arguments, char *buf, unsigned int buf_index);
int print_spaceint(va_list args, char *buf, unsigned int buf_index);
int print_noct(va_list args, char *buf, unsigned int buf_index);
int print_nhex(va_list args, char *buf, unsigned int buf_index);
int print_nupperhex(va_list args, char *buf, unsigned int buf_index);

/* util functions */
int (*get_format_func(const char *s, int index))(va_list, char *, unsigned int);
int all_format_functions(const char *s, int index);
unsigned int handle_buf(char *buf, char c, unsigned int buf_index);
int print_buf(char *buf, unsigned int buf_index);
char *fill_binary_array(char *binary, long int in, int isneg, int limit);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);
char *fill_oct_array(char *binary, char *octal);
#endif
