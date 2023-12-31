#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK	0
#define QUEUE	1

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Gobal variables */
extern char **opcode;

/* function prototypes */
/*void (*f)(stack_t **, unsigned int);*/
stack_t *init_stack();
void (*get_opcode_func(char *str))(stack_t **, unsigned int);
char **parse_line(char *);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void stack(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);
void free_opcode(char **);
int is_digit(char);
int is_number(char *);

/* Linked list funtions*/
size_t print_stack(const stack_t *h);
size_t stack_len(const stack_t *h);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_stack(stack_t *head);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);

#endif
