#include "monty.h"

/**
 * sub - function that substracts the top 2 elements of the stack
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *del;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp = tmp->next;
	tmp->n -= (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}
