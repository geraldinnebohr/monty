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
	stack_t *new, *current;

	if (gbl.num == NULL || is_a_num(gbl.num) == 0)
	{
		dprintf(STDERR_FILENO,
			"L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE); }
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_dlistint(*stack);
		free(gbl.line);
		free(gbl.div_line);
		fclose(gbl.bt_code);
		exit(EXIT_FAILURE); }
	new->n = atoi(gbl.num);
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new; }
	else if (gbl.mode == 1)
	{
		(*stack)->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new; }
	else if (gbl.mode == 0)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		new->next = NULL;
		new->prev = current;
		current->next = new; }
}
