#include "palindrome.h"
/**
 * is_palindrome - checks if palindrome
 *
 * @n: unsigned long
 * Return: 1 if success, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long num1;
	unsigned long num2;

	num1 = 0;
	num2 = n;

	if ((n % 10) == n)
		return (1);

	while (num2 != 0)
	{
		num1 = num1 * 10 + (num2 % 10);
		num2 = num2 / 10;
		if (num1 == n)
			return (1);
	}
	return (0);
}
