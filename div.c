#include "monty.h"

/**
 * division - function that divides the top 2 elements of the stack
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */

void division(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *del;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't div, stack too short\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp = tmp->next;
	tmp->n /= (*stack)->n;
	tmp->prev = NULL;
	del = *stack;
	*stack = tmp;
	free(del);
}
