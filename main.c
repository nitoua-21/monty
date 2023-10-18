#include "monty.h"

char *data = NULL;

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: an interpreter for Monty ByteCodes files.
 *
 * Return: 0 (Success).
 *
 */

int main(int argc, char *argv[])
{
	char *filename, line[100], **opcode;
	FILE *file;
	stack_t *stack = NULL;
	int line_number = 1;
	void (*opcode_func)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	stack = init_stack();
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strlen(line) - 1] = '\0';
		opcode = parse_line(line);
		opcode_func = get_opcode_func(opcode[0]);
		if (!opcode_func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode[0]);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		data = opcode[1];
		opcode_func(&stack, line_number);
		line_number++;
	}

	fclose(file);

	return (0);
}
