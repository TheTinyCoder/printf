#include "main.h"

/**
 * get_specifier_func - returns function for specifier if found
 * @c: character that can represent specifier
 * Return: pointer to function or NULL
 */

int (*get_specifier_func(const char *c))(va_list, char *, int)
{
	int i;
	specifier_funcs funcs[] = {
		{"c", print_char}, {"s", print_str},
		{"d", print_decimal}, {"i", print_integer},
		{"b", print_binary}, {"u", print_uint},
		{"o", print_octal}, {"x", print_hex},
		{"X", print_hex_upper},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].specifier; i++)
	{
		if (*funcs[i].specifier == *c)
			return (funcs[i].f);
	}
	return (NULL);
}
