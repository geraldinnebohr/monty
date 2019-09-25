#include "monty.h"
/**
 * pall - function that prints all the values on the stack
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
