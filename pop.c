#include "monty.h"
/**
 * pop - function that removes the top element of the stack
 * @stack: header of the stack
 * @line_number: number of line in .m file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *nw_last;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->prev == NULL)
		*stack = NULL;
	else
	{
		nw_last = temp->prev;
		nw_last->next = NULL;
		*stack = nw_last;
	}
	free(temp);
}
