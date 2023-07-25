#include <unistd.h>


/**
 * _putchar - function entry-point
 *
 * Description: writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
