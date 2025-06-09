#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: the string
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
	char *msg = "Error\n";

	while (*msg)
		_putchar(*msg++);
	exit(98);
}

/**
 * validate_args - checks arguments validity
 * @argc: argument count
 * @argv: argument vector
 */
void validate_args(int argc, char **argv)
{
	if (argc != 3)
		print_error();
	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error();
}

/**
 * multiply - multiplies two positive numbers given as strings
 * @num1: string num1
 * @num2: string num2
 */
void multiply(char *num1, char *num2)
{
	int len1 = strlen(num1), len2 = strlen(num2);
	int total_len = len1 + len2;
	int *result = calloc(total_len, sizeof(int));
	int i, j, carry, started = 0, n1, n2;

	if (!result)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			result[i + j + 1] += n1 * n2;
		}
	}

	for (i = total_len - 1; i > 0; i--)
	{
		carry = result[i] / 10;
		result[i] %= 10;
		result[i - 1] += carry;
	}

	for (i = 0; i < total_len; i++)
	{
		if (result[i] || started)
		{
			_putchar(result[i] + '0');
			started = 1;
		}
	}
	if (!started)
		_putchar('0');

	_putchar('\n');
	free(result);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	validate_args(argc, argv);
	multiply(argv[1], argv[2]);
	return (0);
}
