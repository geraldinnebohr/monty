#include "monty.h"

/**
 * swap - function that swaps the 2 top elements on the stack
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't swap, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;

	if (tmp->next)
		(tmp->next)->prev = *stack;

	tmp->next = *stack;
	*stack = tmp;
}
