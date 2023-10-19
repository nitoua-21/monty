#include "monty.h"

/**
 * get_opcode_func - selects the correct function
 * for the opcode
 * @str: string
 *
 * Return: pointer to the matching function
 *
 */
void (*get_opcode_func(char *str))(stack_t **, unsigned int)
{
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;

	while (ins[i].opcode != NULL)
	{
		if (strcmp(str, ins[i].opcode) == 0)
			return (ins[i].f);
		i++;
	}
	return (NULL);
}
