#include "holberton.h"

/**
 * wildcmp - Compares two strings and returns 1 if they can be
 *           considered identical (supports '*' wildcard).
 * @s1: First string.
 * @s2: Second string (may contain '*').
 *
 * Return: 1 if identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		/* Skip multiple '*' recursively */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* '*' can match zero or more characters */
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
