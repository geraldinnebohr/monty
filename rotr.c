#include "monty.h"
/**
 * rotr - function that rotates the stack to the bottom.
 * @stack: top of the stack
 * @line_number: # of the line in the .m file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux, *new;
	int nw_n;

	(void)line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			free_dlistint(*stack);
			free(gbl.line);
			free(gbl.div_line);
			fclose(gbl.bt_code);
			exit(EXIT_FAILURE);
		}
		aux = *stack;
		while (aux->next)
			aux = aux->next;
		nw_n = aux->n;
		(aux->prev)->next = NULL;
		free(aux);

		new->n = nw_n;
		(*stack)->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}
