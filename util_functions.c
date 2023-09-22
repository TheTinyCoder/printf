#include "main.h"

/**
 * int_to_str - converts int to str
 * @d: integer
 * Return: string
 */

char *int_to_str(int d)
{
	int i, j = 1, k = 1, l = 0, m = 0;
	char *s;

	if (d < 0 && d != INT_MIN)
		d *= -1, l = 1;
	if (d == INT_MIN)
		d += 1, d *= -1, l = 1, m = 1;
	for (i = d; i > 9; i /= 10)
		j *= 10, k++;
	s = malloc(sizeof(char) * (k + l + 1));
	if (s)
	{
		if (l > 0)
			s[0] = '-';
		for (i = l; i < k + l; i++)
			s[i] = 48 + (d / j), d %= j, j /= 10;
		s[i - 1] += m, s[i] = '\0';
		return (s);
	}
	return (NULL);

}


/**
 * _atoi - converts str to int
 * @s: string
 * Return: int
 */

int _atoi(const char *s)
{
	int i = 0, j = 1, k, l = 0, neg = 0;

	if (s[0] == '-')
		neg = 1;

	for (; s[i]; i++)
		j *= neg == 1 && i == 0 ? 1 : 10;
	j /= 10;
	for (k = neg; k < i; k++)
		l += ((s[k] - 48) * j), j /= 10;

	l *= neg == 1 ? -1 : 1;
	return (l);
}


/**
 * _strcmp -  function entry-point
 *
 * Description: 'compares specifier to input string'
 * @s1: specifier string
 * @s2: input string
 * Return: 1 if strings are equal, 0 otherwise
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != *(s2 + i))
			return (0);
	}

	return (1);
}


/**
 * _strlen - function entry-point
 *
 * Description: returns the length of a string
 * @s: pointer to array
 * Return: int
 */

int _strlen(char *s)
{
	int x = 0;

	while (s[x])
		x++;
	return (x);
}
