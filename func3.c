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
 * change_mode - changes the mode of interpreter.
 * @stack: address of stack pointer.
 * @mode: stack mode.
 */
void change_mode(stack_t **stack, int mode)
{

