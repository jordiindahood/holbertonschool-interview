#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if the strings
 *           can be considered identical (supports '*')
 * @s1: first string
 * @s2: second string (may contain '*')
 *
 * Return: 1 if identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		/* Skip multiple '*' in a row */
		while (*(s2 + 1) == '*')
			s2++;

		/* '*' can match empty or any substring */
		if (wildcmp(s1, s2 + 1))
			return (1);

		if (*s1 && wildcmp(s1 + 1, s2))
			return (1);

		return (0);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
