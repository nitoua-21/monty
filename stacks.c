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

/**
 * push -  pushes an element to the stack.
 * @stack: pointer to stack top
 * @line_number: line number in input file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (opcode[1] == NULL || (is_number(opcode[1]) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_opcode(opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
		node = insert_dnodeint_at_index(stack, 1, atoi(opcode[1]));
	else
		node = add_dnodeint_end(stack, atoi(opcode[1]));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall -  rints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to stack top
 * @line_number: line number in input file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	size_t len = stack_len(*stack);
	stack_t *tmp;
	(void) line_number;

	if (len > 1)
	{
		tmp = *stack;
		tmp = tmp->next;
		print_stack(tmp);
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack top
 * @line_number: line number in input file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);
}
