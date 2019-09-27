#include "monty.h"
/**
 * pstr - function that prints the string on the top of the stack
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
		return;
	}
	while (current->n > 0 && current->n <= 127)
	{
		c = current->n;
		printf("%c", c);
		if (current->next == NULL)
			break;
		current = current->next;
	}
	printf("\n");
}
