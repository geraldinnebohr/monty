#include "monty.h"

/**
 * pchar - function that prints the char at the top of the stack
 * @stack: header of the stack
 * @line_number: # of the line in the .m file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	char c = (*stack)->n;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 127)
	{
		dprintf(STDERR_FILENO,
			"L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}