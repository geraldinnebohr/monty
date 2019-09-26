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

	divide = malloc(5 * sizeof(char *));
	divide[i] = strtok(line, " \n");
	while (divide[i])
	{
		i++;
		divide[i] = strtok(NULL, " \n");
	}
	divide[i + 1] = NULL;
	return (divide);
}

/**
 * select_instruction - function that sort the opcodes
 * @bt_code: .m file
 * Return: Void function
 */
void select_instruction(FILE *bt_code)
{
	int c, flag;
	unsigned int line_number, i;
	char line[50], **div_line;
	stack_t *stack;
	instruction_t selector[] = {{"push", push}, {"pall", pall},
				    {"pint", pint}, {"pop", pop},
				    {"swap", swap}, {"add", add},
				    {"nop", nop}, {"sub", sub},
				    {"div", division}, {"mul", mul},
				    {"mod", mod}, {"pchar", pchar},
				    {NULL, NULL}};
	stack = NULL;
	line_number = 1;
	while (fgets(line, sizeof(line), bt_code) != NULL)
	{
		div_line = get_div_line(line);
		gbl = div_line[1];
		i = 0;
		flag = 1;
		while (selector[i].opcode != NULL)
		{
			if (div_line[0][0] == '#')
			{nop(&stack, line_number);
				flag = 0;
				break; }
			c = strcmp(div_line[0], selector[i].opcode);
			if (c == 0)
			{
				selector[i].f(&stack, line_number);
				flag = 0;
				break; }
			i++; }
		if (flag)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
				line_number, div_line[0]);
			exit(EXIT_FAILURE); }
		line_number++;
		free(div_line); }
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
	FILE *bt_code;

	if (ac < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bt_code = fopen(av[1], "r");
	if (bt_code == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	select_instruction(bt_code);
	fclose(bt_code);
	return (0);
}
