#define GLOBALS
#include "monty.h"


/**
 * get_div_line - function that tokenizes the line
 * @line: is a character
 * Return: arrays of strings
 */
char **get_div_line(char *line)
{
	char **divide;
	int i = 0;

	divide = malloc(1024 * sizeof(char *));
	divide[i] = strtok(line, " \n\t");
	if (divide[i] == NULL)
	{
		free(divide);
		return (NULL);
	}
	while (divide[i])
	{
		i++;
		divide[i] = strtok(NULL, " \n\t");
	}
	divide[i + 1] = NULL;
	return (divide);
}

