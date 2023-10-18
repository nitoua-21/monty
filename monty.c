#include "monty.h"
/**
 * main - interpretes monty bytecode
 * @argc: command line argument count
 * @argv: command line arguments
 * Return: 0 (Always success)
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char line[3000], **opcode;
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %S", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = fgets(line, 3000, f);
		if (!line)
			break;
		opcode = parse_arguments(line);
		interpret(opcode, line_number);
		line_number++;
	}
	return (EXIT_SUCCESS);
}
/**
 * parse_arguments - splits line input into individual strings
 * @input: line to be parsed
 * Return: tokenized line
 */
char **parse_arguments(char *input)
{
	char **code, *token;
	int i = 0;

	code = malloc(sizeof(char *) * 5);
	if (!code)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(input, " \t");
	while (token)
	{
		code[i] = token;
		token = strtok(NULL, " \t");
		i++;
	}

	return (code);
}

/**
 * interpret - interprets the opcode
 * @op: opcode
 * Return: none
 */
void 
