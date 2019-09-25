#define "monty.h"

/**
 * push - function that pushes an element to the stack
 * stack - header of the stack
 * line_number - line of the line in the .m file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *opcode;
	char *delim;

	(void)line_number;
	delim = "\t \a\n";
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error");
		exit();
	}

	opcode = strtok(NULL, delim);

	new->n = atoi(opcode);
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}
