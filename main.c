#define GLOBALS
#include "monty.h"
char **get_div_line(char *line)
{
	char **div;
	int i = 0;

	div = malloc(10 * sizeof(char *));
	div[i] = strtok(line, " \n");
	while (div[i])
	{
		i++;
		div[i] = strtok(NULL, " \n");
	}
	return (div);
}
void select_instruction(FILE *bt_code)
{
	int c, flag;
	unsigned int line_number, i;
	char line[50];
	char **div_line;
	stack_t *stack;
	instruction_t selector[] = {{"push", push}, {"pall", pall},
				    {"pint", pint}, {"pop", pop},/*
				    {"swap", swap}, {"add", add},*/
				    {"nop", nop},{NULL, NULL}};
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
			c = strcmp(div_line[0], selector[i].opcode);
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
			printf("L%u: unknown instruction %s\n",
			       line_number, div_line[0]);
				exit(EXIT_FAILURE);
		}
		line_number++;
	}
}
int main(int ac, char **av)
{
	FILE *bt_code;

	if (ac < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bt_code = fopen(av[1], "r");
	if (bt_code == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	select_instruction(bt_code);
	fclose(bt_code);
	return (0);
}
