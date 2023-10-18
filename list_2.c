#include "monty.h"

/**
 * print_stack - prints all the elements of a stack_t list.
 * @h: pointer to header node
 *
 * Return: the number of nodes
 */
size_t print_stack(const stack_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * stack_len - counts the number of elements in a linked stack_t list.
 * @h: pointer to head node
 *
 * Return: number of elements in a linked stack_t list.
 */
size_t stack_len(const stack_t *h)
{
	size_t len = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		len++;
		h = h->next;
	}

	return (len);
}

/**
 * insert_dnodeint_at_index -  inserts a new node at a given position.
 * @h: pointer to head node pointer.
 * @idx: index of the list where the new node should be added.
 * @n: data
 *
 * Return: the address of the new node, or NULL if it failed
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *node, *tmp;
	unsigned int step = 0;

	if (h == NULL)
		return (NULL);
	if (*h == NULL && idx > 0)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = NULL, node->prev = NULL;
	if (*h == NULL && idx == 0)
	{
		*h = node;
		return (node);
	}
	tmp = *h;
	if (idx == 0)
	{
		node->next = tmp;
		tmp->prev = node;
		*h = node;
		return (node);
	}
	while (tmp != NULL && step < idx)
	{
		if (step == idx - 1)
		{
			node->prev = tmp, node->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = node;
			tmp->next = node;
			return (node);
		}
		step++;
		tmp = tmp->next;
	}
	free(node);
	return (NULL);
}
