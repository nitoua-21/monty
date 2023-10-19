#include "monty.h"
/**
 * rotl - rotates stack to the top.
 * @stack: address of stack pointer
 * @line_number: line number
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (!(copy->next) || !(copy->next->next))
		return;

	copy = copy->next;

	add_dnodeint_end(&copy, copy->n);
	pop(stack, line_number);
}

/**
 * rotr - rotates stack to the bottom.
 * @stack: address of stack pointer
 * @line_number: line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack, *tmp;
	char last_number[10] = "";

	if (!(copy->next) || !(copy->next->next))
		return;

	copy = copy->next;

	while (copy->next)
		copy = copy->next;

	tmp = copy;
	/* converting last int into str to assign to opcode[1], a string*/
	sprintf(last_number, "%d", copy->n);

	opcode[1] = strdup(last_number);
	/*opcode[0] = strdup("push");*/
	push(stack, line_number);

	tmp->prev->next = NULL;

	free(tmp);
}

/**
 * stack - sets the format of the data to a stack (LIFO).
 * @stack: address of stack pointer
 * @line_number: line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	(*stack)->n = STACK;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: address of stack pointer
 * @line_number: line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	(*stack)->n = QUEUE;
}
