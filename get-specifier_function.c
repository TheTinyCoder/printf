#include "main.h"

/**
 * get_specifier_func - returns function for specifier if found
 * @c: pointer to format string
 * Return: pointer to struct with function or NULL
 */

specifier_funcs *get_specifier_func(const char *c)
{
	int i;
	specifier_funcs funcs[] = {
		{"c", print_char}, {"s", print_str}, {"d", print_decimal},
		{"i", print_integer}, {"b", print_binary}, {"u", print_uint},
		{"o", print_octal}, {"x", print_hex}, {"X", print_hex_upper},
		{"S", print_custom_str}, {"p", print_address},
		{"%", print_percent}, {"ld", print_long_decimal},
		{"li", print_long_integer}, {"lu", print_long_uint},
		{"lx", print_long_hex}, {"lX", print_long_hex_upper},
		{"lo", print_long_octal}, {"hd", print_short_decimal},
		{"hi", print_short_integer}, {"hu", print_short_uint},
		{"hx", print_short_hex}, {"hX", print_short_hex_upper},
		{"ho", print_short_octal},
		{NULL, NULL}
	};
	specifierFuncPtr ptr;

	ptr = malloc(sizeof(specifier_funcs));
	for (i = 0; funcs[i].specifier; i++)
	{
		if (_strcmp(funcs[i].specifier, c))
		{
			*ptr = funcs[i];
			return (ptr);
		}
	}
	return (NULL);
}

/**
 * print_percent - function entry-point
 *
 * Description: prints percent
 * @args: va_list (unused)
 * @buf: buffer
 * @index: buffer index
 * @ptr: identifierPtr (unused)
 * Return: number of bytes printed
 */

int print_percent(va_list args, char *buf, int index, identifierPtr ptr)
{
	(void)args, (void)ptr;
	use_buffer(buf, index, '%');
	return (1);
}
