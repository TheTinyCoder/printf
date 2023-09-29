#include "main.h"

/**
 * get_identifiers - returns format identifiers
 * @args: va_list
 * @c: pointer to format string
 * Return: pointer to identifiers or NULL
 */

identifiers *get_identifiers(va_list args, const char *c)
{
	int i = 0, j = 0, k = 0, width = 0;
	identifierPtr ptr = malloc(sizeof(identifiers));
	specifierFuncPtr funcPtr;
	char flags[5] = {'\0', '\0', '\0', '\0', '\0'};

	ptr->flags = flags, ptr->width = 0, ptr->period = 0, ptr->precision = 0;
	for (; c[i]; i++)
	{
		if ((c[i] == '+' || c[i] == ' ' || c[i] == '-' ||
					c[i] == '0' || c[i] == '#') && j < 5)
		{
			flags[j] = c[i], j++;
			continue;
		}
		if (c[i] > 47 && c[i] < 58)
		{
			k *= 10, k += c[i] - 48;
			continue;
		}
		if (c[i] == '*' && width == 0 && !ptr->period)
			ptr->width = va_arg(args, int), width = 1;
		else if (c[i] == '*' && ptr->period)
			ptr->precision = va_arg(args, int);
		if (!ptr->period && width == 0)
			ptr->width = k, k = 0, width = 1;
		if (c[i] == '.')
		{
			ptr->period = 1;
			continue;
		}
		if (ptr->period)
			ptr->precision = k, k = 0;
		if (!(c[i] > 47 && c[i] < 58))
		{
			funcPtr = get_specifier_func(&c[i]), ptr->ptr = funcPtr;
			i += funcPtr ? _strlen(funcPtr->specifier) : 0, ptr->n = i;
			break;
		}
	}
	return (ptr);
}
