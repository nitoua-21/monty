#include "monty.h"

/**
 * parse_line - parses each line into an array of he opcode and its argument.
 * @str: string
 *
 * Return: tokens
 */
char **parse_line(char *str)
{
	char **tokens = NULL, *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
		return (NULL);
	token = strtok(str, " \t");
	while (token != NULL && i < 2)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \t");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
