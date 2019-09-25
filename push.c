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
	stack_t *new, *end;
	char* opcode = "h";

	if (opcode == NULL)
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
		end = *stack;
		new->n = atoi(gbl);
		new->next = NULL;
		while (end->next != NULL)
			end = end->next;
		end->next = new;
		new->prev = end;
	}
}
