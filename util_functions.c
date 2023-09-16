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
