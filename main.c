#define GLOBALS
#include "monty.h"

/**
 * select_instruction - function that sort the opcodes
 *
 * Return: Void function
 */
void select_instruction(void)
{
	size_t l_sz = 0;
	stack_t *stack;

	gbl.mode = 1;
	gbl.line = NULL;
	stack = NULL;
	gbl.line_number = 1;
	while (getline(&(gbl.line), &l_sz, gbl.bt_code) != -1)
	{
		gbl.div_line = get_div_line(gbl.line);
		if (gbl.div_line == NULL)
		{
			gbl.line_number++;
			continue;
		}
		gbl.num = gbl.div_line[1];
		exe_function(&stack);
		if (strcmp(gbl.div_line[0], "stack") == 0)
			gbl.mode = 1;
		else if (strcmp(gbl.div_line[0], "queue") == 0)
			gbl.mode = 0;
		gbl.line_number++;
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
	if (ac != 2)
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
