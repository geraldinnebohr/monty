#include "monty.h"
/**
 * _isdigit - parameter is a num or not.
 * Return: 1 if c is num, 0 otherwhise
 * @c: parameter
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * is_a_num - function that verifies if the variable is a number
 * @n: is a character
 * Return: 1 if success or 0 if not
 */
int is_a_num(char *n)
{
	int i = 0;

	if (n[i] == '-')
	{
		i++;
		if (n[i] == '\0')
			return (0);
	}
	for (; n[i]; i++)
	{
		if (_isdigit(n[i]) == 0)
			return (0);
	}
	return (1);
}
