#define "monty.h"

/**
 * pop - function that removes the top element of the stack
 * @stack: header of the stack
 * @line_number: number of line in .m file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ant, *temp;

	ant = *stack;
	if (ant == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty", line_number);
		exit();
	}

	temp = ant;
	ant->next = temp->next;
	free(ant);
}
