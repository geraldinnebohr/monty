#include "monty.h"
/**
 * pop - function that removes the top element of the stack
 * @stack: header of the stack
 * @line_number: number of line in .m file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *nw_stack;

	(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pop an empty stack\n", gbl.line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next == NULL)
		*stack = NULL;
	else
	{
		nw_stack = temp->next;
		nw_stack->prev = NULL;
		*stack = nw_stack;
	}
	free(temp);
}
