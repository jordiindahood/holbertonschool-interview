#include "regex.h"

/**
 * regex_match - checks if a pattern matches a string
 * @str: the string to check
 * @pattern: the pattern to match
 *
 * Return: 1 if match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	/* If pattern is empty: match only if string is also empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if first char matches (or pattern[0] == '.') */
	int first_match = (*str != '\0' &&
					   (*str == *pattern || *pattern == '.'));

	/* Handle the * operator */
	if (pattern[1] == '*')
	{
		/**
		 * Two recursive paths:
		 * 1. Skip "x*" entirely → regex_match(str, pattern + 2)
		 * 2. Consume one char IF first matches → regex_match(str + 1, pattern)
		 */
		return (regex_match(str, pattern + 2) ||
			   (first_match && regex_match(str + 1, pattern)));
	}

	/* No wildcard: match current char + move on */
	return (first_match && regex_match(str + 1, pattern + 1));
}
