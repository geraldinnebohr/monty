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

/**
 * select_instruction - function that sort the opcodes
 *
 * Return: Void function
 */
void select_instruction(void)
{
	int c, flag;
	unsigned int line_number, i;
	size_t l_sz = 0;
	stack_t *stack;
	instruction_t selector[] = {{"push", push}, {"pall", pall},
				    {"pint", pint}, {"pop", pop},
				    {"swap", swap}, {"add", add},
				    {"nop", nop}, {"sub", sub},
				    {"div", division}, {"mul", mul},
				    {"mod", mod}, {"pchar", pchar},
				    {NULL, NULL}};
	gbl.line = NULL, stack = NULL, line_number = 1;
	while (getline(&(gbl.line), &l_sz, gbl.bt_code) != -1)
	{
		gbl.div_line = get_div_line(gbl.line);
		if (gbl.div_line == NULL)
		{
			line_number++;
			continue;
		}
		gbl.num = gbl.div_line[1];
		i = 0;
		flag = 1;
		while (selector[i].opcode != NULL)
		{
			if (gbl.div_line[0][0] == '#')
			{
				nop(&stack, line_number);
				flag = 0;
				break;
			}
			c = strcmp(gbl.div_line[0], selector[i].opcode);
			if (c == 0)
			{
				selector[i].f(&stack, line_number);
				flag = 0;
				break;
			}
			i++;
		}
		if (flag)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
				line_number, gbl.div_line[0]);
			free_dlistint(stack);
			free(gbl.line);
			free(gbl.div_line);
			fclose(gbl.bt_code);
			exit(EXIT_FAILURE);
		}
		line_number++;
		free(gbl.div_line);
	}
	free(gbl.line);
	free_dlistint(stack);
}
/**
 * main - function that calls the opcodes
 * @ac: is an integer
 * @av: is a character
 * Return: Always 0
 */
int main(int ac, char **av)
{
	if (ac < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	gbl.bt_code = fopen(av[1], "r");
	if (gbl.bt_code == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	select_instruction();
	fclose(gbl.bt_code);
	return (0);
}
