#ifndef main_h
#define main_h

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
typedef struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);

/* Helper functions */
int (*get_format(const char *s, int index))(va_list, char[], int, int, int, int);
int all_format_functions(const char *s, int index);
unsigned int handle_buf(char buffer[], char c, unsigned int buf_index);
int print_buf(char buffer[], unsigned int buf_index);
char *fill_binary_array(char binary[], long int num, int isneg, int limit);
char *fill_hex_array(char bnr[], char hex[], int isupp, int limit);
char *fill_oct_array(char binary[], char octal[]);

/* Conversion specifiers */
int print_char(va_list types, char buffer[],
              int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
                  int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
              int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
                   int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
                       int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
                      int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
               char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
                         int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
                   int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
                   int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
                       int flags, int width, int precision, int size);

/* Flag handling functions */
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list list);
int get_precision(const char *format, int *index, va_list list);
int get_size(const char *format, int *index);

/* Write functions */
int write_number(int is_positive, int index, char buffer[],
                  int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision,
              int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int index,
                  char buffer[],
                  int flags, int width, int precision, int size);
int is_printable(char c);
int append_hexa_code(char c, char hex[], int index);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
