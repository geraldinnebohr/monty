#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack
 * @stack: header of the stack
 * @line_number: # of the line in the .m file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pint, stack empty\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
