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
		dprintf(STDERR_FILENO, "L<line_number>: can't pint, stack empty");
		exit(EXIT_FAILURE);
	}

	if (stack->next = NULL)
		printf("%d\n", stack->n);
}
