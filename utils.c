#include "monty.h"

/**
 * free_opcode - frees opcode tokens
 * @opcode: opcode
 */
void free_opcode(char **opcode)
{
	int i = 0;

	while (opcode[i] != NULL)
		free(opcode[i++]);
	free(opcode);
}

/**
 * is_digit - checks if a character is a digit
 * @c: char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * is_number - check if a string is a number
 * @str: string
 *
 * Return: 1 if str is a number, 0 otherwise
 */
int is_number(char *str)
{
	int i;

	if (str == NULL || str[0] == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		if (is_digit(str[i]) == 0)
			return (0);
	return (1);
}
