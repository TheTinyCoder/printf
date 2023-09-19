#include "main.h"

/**
 * use_buffer - uses a buffer of 1024 and prints when filled
 * @buf: buffer
 * @index: buffer index
 * @c: character to add to buffer
 * Return: void
 */

void use_buffer(char *buf, int index, char c)
{
	if (index == BUF_SIZE)
		print_buffer(buf, index);
	buf[index] = c;
}


/**
 * print_buffer - prints buffer
 * @buf: buffer
 * @size: buffer size to print
 * Return: void
 */

void print_buffer(char *buf, int size)
{
	write(1, buf, size);
}
