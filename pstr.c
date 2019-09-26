#include "monty.h"
/**
 * pall - function that prints all the values on the stack
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	char c;
	(void)line_number;

	current = *stack;

	if (current == NULL)
	{
		printf("\n");
		exit(EXIT_FAILURE);
	}

	while (current->n != 0)
	{
		c = current->n;
		if (current->n < 0 || current->n > 127)
		{
			printf("\n");
			exit(EXIT_FAILURE);
		}
		printf("%c", c);
		current = current->next;
	}
	printf("\n");
}
