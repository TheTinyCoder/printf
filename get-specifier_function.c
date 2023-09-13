#include "main.h"

/**
 * get_specifier_func - returns function for specifier if found
 * @c: character that can represent specifier
 * Return: pointer to function or NULL
 */

int (*get_specifier_func(const char *c))(const char *)
{
	int i;
	specifier_funcs funcs[] = {
		{"c", print_char}, {"s", print_str},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].specifier; i++)
	{
		if (*funcs[i].specifier == *c)
			return (funcs[i].f);
	}
	return (NULL);
}
