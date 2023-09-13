#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - function entry-point
 *
 * Description: writes the character c to stdout (prints a character)
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: 1 (on success)
 */

int print_char(va_list args, char *buf, unsigned int buf_index)
{
	char c;

	c = va_arg(args, int);
	handle_buf(buf, c, buf_index);

	return (1);
}


/**
 * print_percent - function entry-point
 * Description: writes the character c to stdout
 * @a: input charater
 * @buf: pointer to buffer
 * @i: index for buffer pointer
 * Return: On success 1.
 */

int print_percent(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handle_buf(buf, '%', i);

	return (1);
}


/**
 * print_str - function entry-point
 * Description: writes the string to stdout(prints a string)
 * @args: arguments
 * @buf: pointer to buffer
 * @buf_index: index for buffer pointer
 * Return: 1 (on success)
 */

int print_str(va_list args, char *buf, unsigned int buf_index)
{
	char *str, nil[] = "(null)";
	unsigned int i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nil[i]; i++)
			buf_index = handle_buf(buf, nil[i], buf_index);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buf_index = handle_buf(buf, str[i], buf_index);
	return (i);
}
