#include "main.h"
#include <unistd.h>

/**
 * handle_buf - concatenates the buffer characters
 * @buf: pointer to buffer
 * @c: character to concatenate
 * @buf_index: index of buffer pointer
 * Return: index of buffer pointer.
 */

unsigned int handle_buf(char *buf, char c, unsigned int buf_index)
{
	if (buf_index == 1024)
	{
		print_buf(buf, buf_index);
		buf_index = 0;
	}
	buf[buf_index] = c;
	buf_index++;
	return (buf_index);
}


/**
 * print_buf - prints buffer
 * @buf: pointer to buffer
 * @nbytes: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buf(char *buf, unsigned int nbytes)
{
	return (write(1, buf, nbytes));
}


#include "main.h"
/**
 * all_format_functions - returns the number of identifiers.
 * @s: argument indentifier
 * @index: index of argument identifier.
 * Return: number of identifiers.
 */
int all_format_functions(const char *s, int index)
{
	print_format print[] = {
		{"c", print_char}, {"s", print_str}, {"i", print_int}, {"d", print_int},
		{" %", print_percent}, {"u", print_uint}, {"o", print_oct}, {"x", print_hex},
		{"X", print_upperhex}, {"S", print_string_S}, {"p", print_address}, {"#o", print_noct},
		{"#x", print_nhex}, {"#X", print_nupperhex}, {"#i", print_int}, {"#d", print_int},
		{"#u", print_uint}, {"+i", print_plusint}, {"+d", print_plusint}, {"+u", print_uint},
		{"+o", print_oct}, {"+x", print_hex}, {"+X", print_upperhex}, {" i", print_spaceint},
		{" d", print_spaceint}, {" u", print_uint}, {" o", print_oct}, {" x", print_hex},
		{" X", print_upperhex}, {"li", print_lint}, {"ld", print_lint}, {"lu", print_luint},
		{"lo", print_loct}, {"lx", print_lhex}, {"lX", print_lupperhex}, {"hi", print_shortint},
		{"hd", print_shortint}, {"hu", print_shortuint}, {"ho", print_shortoct}, {"hx", print_shorthex},
		{"hX", print_shortupperhex}, {NULL, NULL}
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (print[i].format)
	{
		if (s[index] == print[i].format[j])
		{
			if (print[i].format[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (j);
}


/**
 * get_format_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_format_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_format print[] = {
		{"c", print_char}, {"s", print_str}, {"i", print_int}, {"d", print_int},
		{" %", print_percent}, {"u", print_uint}, {"o", print_oct}, {"x", print_hex},
		{"X", print_upperhex}, {"S", print_string_S}, {"p", print_address}, {"#o", print_noct},
		{"#x", print_nhex}, {"#X", print_nupperhex}, {"#i", print_int}, {"#d", print_int},
		{"#u", print_uint}, {"+i", print_plusint}, {"+d", print_plusint}, {"+u", print_uint},
		{"+o", print_oct}, {"+x", print_hex}, {"+X", print_upperhex}, {" i", print_spaceint},
		{" d", print_spaceint}, {" u", print_uint}, {" o", print_oct}, {" x", print_hex},
		{" X", print_upperhex}, {"li", print_lint}, {"ld", print_lint}, {"lu", print_luint},
		{"lo", print_loct}, {"lx", print_lhex}, {"lX", print_lupperhex}, {"hi", print_shortint},
		{"hd", print_shortint}, {"hu", print_shortuint}, {"ho", print_shortoct}, {"hx", print_shorthex},
		{"hX", print_shortupperhex}, {NULL, NULL}

	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (print[i].format)
	{
		if (s[index] == print[i].format[j])
		{
			if (print[i].format[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (print[i].f);
}
