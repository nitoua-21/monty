#include "monty.h"

/**
 * _div - subtracts top two elements into the second top element
 * and pops the top.
 * @stack: address of stack pointer
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	tmp = tmp->next;
	if (stack_len(tmp) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	tmp->next->n = tmp->next->n / tmp->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the top two elements into the second top element
 * and pops the top.
 * @stack: address of stack pointer
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	tmp = tmp->next;
	if (stack_len(tmp) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	tmp->next->n = tmp->next->n * tmp->n;
	pop(stack, line_number);
}

/**
 * mod - finds the modulus of top two elements into the second top element
 * and pops the top.
 * @stack: address of stack pointer
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	tmp = tmp->next;
	if (stack_len(tmp) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	tmp->next->n = tmp->next->n % tmp->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the top element as an ascii char.
 * @stack: address of stack pointer
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!(top->next))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	top = top->next;

	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		free_opcode(opcode);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)top->n);
}

/**
 * pstr - prints numbers as a ascii chars, into a string
 * @stack: address of stack pointer
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void) line_number;

	top = top->next;

	while (top)
	{
		if (top->n > 127 || top->n <= 0)
			break;

		printf("%c", (char)top->n);
		top = top->next;
	}

	printf("\n");
}
