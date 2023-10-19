#include "monty.h"

/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: pointer to stack top
 * @line_number: line number in input file
 */
void swap(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp1, *tmp2;

	if ((*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}
}
