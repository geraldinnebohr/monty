#define GLOBALS
#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @stack: header of the stack
 * @line_number: number of line in the .m file
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (is_a_num(gbl) == 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new->n = atoi(gbl);
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
	        new->n = atoi(gbl);
		new->prev = *stack;
		new->next = NULL;
		*stack = new;
	}
}
