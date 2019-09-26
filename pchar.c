#include "monty.h"

/**
 * pchar - function that prints the char at the top of the stack
 * @stack: header of the stack
 * @line_number: # of the line in the .m file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	char c;

	(void)line_number;
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, stack empty\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, value out of range\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c);
}
