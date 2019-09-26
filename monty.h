#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern void push(stack_t **stack, unsigned int line_number);
extern void pall(stack_t **stack, unsigned int line_number);
extern void pint(stack_t **stack, unsigned int line_number);
extern void pop(stack_t **stack, unsigned int line_number);
extern void swap(stack_t **stack, unsigned int line_number);
extern void add(stack_t **stack, unsigned int line_number);
extern void nop(stack_t **stack, unsigned int line_number);
extern void sub(stack_t **stack, unsigned int line_number);
extern void division(stack_t **stack, unsigned int line_number);
extern void mul(stack_t **stack, unsigned int line_number);
int is_a_num(char *n);
void free_dlistint(stack_t *head);

#ifdef GLOBALS
char *gbl;
#else
extern char *gbl;
#endif

#endif
