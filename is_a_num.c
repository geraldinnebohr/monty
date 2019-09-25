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

int is_a_num(char *n)
{
	int i;

	for (i = 0; n[i]; i++)
	{
		if (_isdigit(n[i]) == 0)
			return (0);
	}
	return (1);
}
