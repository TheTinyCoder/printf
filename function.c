#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * ...helper functions ...
 */

/**
 * _printf - A custom printf function
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            int align_left = 0;
            int zero_padding = 0;
            int field_width = 0;
            int precision = -1;

            while (*format == '-' || *format == '0')
            {
                if (*format == '-')
                {
                    align_left = 1;
                }
                else if (*format == '0')
                {
                    zero_padding = 1;
                }
                format++;
            }

            while (*format >= '0' && *format <= '9')
            {
                field_width = field_width * 10 + (*format - '0');
                format++;
            }

            if (*format == '.')
            {
                format++;
                precision = 0;
                while (*format >= '0' && *format <= '9')
                {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
            }

            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    if (field_width > 1)
                    {
                        char_count += print_with_padding(c, field_width, align_left);
                    }
                    else
                    {
                        _putchar(c);
                        char_count++;
                    }
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    char_count += print_string(s, field_width, precision, align_left, zero_padding);
                    break;
                }
                case '%':
                {
                    if (field_width > 1)
                    {
                        char_count += print_with_padding('%', field_width, align_left);
                    }
                    else
                    {
                        _putchar('%');
                        char_count++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    char_count += print_integer(num, field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_unsigned(num, field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_octal(num, field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_hexadecimal(num, 'x', field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_hexadecimal(num, 'X', field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_binary(num, field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(args, void *);
                    char_count += print_pointer_address(ptr, field_width, precision, align_left);
                    break;
                }
                case 'S':
                {
                    char *s = va_arg(args, char *);
                    char_count += print_custom_string(s, field_width, precision, align_left, zero_padding);
                    break;
                }
                case 'r':
                {
                    char *s = va_arg(args, char *);
                    char_count += print_reversed_string(s, field_width, precision, align_left);
                    break;
                }
                case 'R':
                {
                    char *s = va_arg(args, char *);
                    char_count += print_rot13_string(s, field_width, precision, align_left);
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        else
        {
            _putchar(*format);
            char_count++;
        }

        format++;
    }

    va_end(args);

    return char_count;
}
