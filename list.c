#include "monty.h"

/**
 * add_dnodeint -  adds a new node at the beginning of a stack_t list.
 * @head: pointer to head node pointer
 * @n: data
 *
 * Return: ddress of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	/*If head node*/
	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}
	(*head)->prev = node;
	node->next = *head;
	*head = node;

	return (node);
}

/**
 * add_dnodeint_end -  adds a new node at the end of a stack_t list.
 * @head: pointer to head node pointer
 * @n: data
 *
 * Return: ddress of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *node, *tmp;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	/*If first node*/
	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = node;
	node->prev = tmp;

	return (node);
}

/**
 * free_stack - frees a stack_t list.
 * @head: pointer to head node
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * delete_dnodeint_at_index - deletes the node at index
 * of a stack_t linked list.
 * @head: pointer to head node pointer
 * @index:  index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp, *tmp2;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;
	if (index == 0)
	{
		if (tmp->next != NULL)
		{
			tmp->next->prev = NULL;
			*head = tmp->next;
			free(tmp);
			return (1);
		}
		free(tmp);
		*head = NULL;
		return (1);
	}
	while (tmp != NULL && i < index)
	{
		if (i == index - 1)
		{
			tmp2 = tmp->next;
			if (tmp2->next != NULL)
			{
				tmp->next = tmp2->next;
				tmp2->next->prev = tmp;
			}
			else
				tmp->next = NULL;
			free(tmp2);
			return (1);
		}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

/**
 * get_dnodeint_at_index - finds the nth node of a stack_t linked list.
 * @head: pointer to head node
 * @index: index of the node
 *
 * Return: the nth node of a stack_t linked list.
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while (head != NULL)
	{
		if (i == index)
			return (head);
		if (i > index)
			return (NULL);
		head = head->next;
		i++;
	}
	return (NULL);
}
