#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack
 * @stack: header of the stack
 * @line_number: # of the line in the .m file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
