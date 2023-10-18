#include "monty.h"

/**
 * init_stack - initializes the stack to LIFO mode
 *
 * Return: pointer to node or NULL
 */
stack_t *init_stack()
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failedi\n");
		exit(EXIT_FAILURE);
	}
	stack->n = STACK;
	stack->prev = NULL;
	stack->next = NULL;

	return (stack);
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (data == NULL || (strcmp(data, "0") != 0 && atoi(data) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node = insert_dnodeint_at_index(stack, 1, atoi(data));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failedi\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
void pall(stack_t **stack, unsigned int line_number)
{
	*stack = (*stack)->next;
	print_stack(*stack);
}
