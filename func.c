#include "monty.h"

/**
 * pop - removes top element
 * @stack: address of stack pointer
 * @line_number: line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(tmp->next))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	tmp = tmp->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps top two elements of a stack.
 * @stack: address of a stack pointer
 * @line_number: line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int first_num;

	tmp = tmp->next;

	if (stack_len(tmp) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	first_num = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = first_num;
}

/**
 * add - adds top two elements into the second top element and pops the top.
 * @stack: address of stack pointer
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	tmp = tmp->next;
	if (stack_len(tmp) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	tmp->next->n = tmp->n + tmp->next->n;
	pop(stack, line_number);
}
/**
 * nop - does nothing
 * @stack: address of stack pointer
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
