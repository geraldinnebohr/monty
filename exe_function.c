#define GLOBALS
#include "monty.h"
/**
 * exe_function - select and exe a function
 * @stack: linked list
 * Return: nothing
 */
void exe_function(stack_t **stack)
{
	instruction_t selector[] = {{"push", push}, {"pall", pall},
				    {"pint", pint}, {"pop", pop},
				    {"swap", swap}, {"add", add},
				    {"nop", nop}, {"sub", sub},
				    {"div", division}, {"mul", mul},
				    {"mod", mod}, {"pchar", pchar},
				    {"rotl", rotl}, {"rotr", rotr},
				    {"pstr", pstr}, {"stack", nop},
				    {"queue", nop}, {NULL, NULL}};
	int flag = 1, i = 0, c;

	while (selector[i].opcode != NULL)
	{
		if (gbl.div_line[0][0] == '#')
		{
			nop(stack, gbl.line_number);
			flag = 0;
			break;
		}
		c = strcmp(gbl.div_line[0], selector[i].opcode);
		if (c == 0)
		{
			selector[i].f(stack, gbl.line_number);
			flag = 0;
			break;
		}
		i++;
	}
	if (flag)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
			gbl.line_number, gbl.div_line[0]);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}
}

