#include "monty.h"

char **opcode = NULL;

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
	char line[1024];
	FILE *file;
	stack_t *stack = NULL;
	int line_number = 1;
	void (*opcode_func)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = init_stack();
	while (fgets(line, sizeof(line), file) != NULL)
	{	line[strlen(line) - 1] = '\0';
		opcode = parse_line(line);
		if (opcode[0] == NULL)
		{
			free_opcode(opcode), line_number++;
			continue;
		}
		opcode_func = get_opcode_func(opcode[0]);
		if (opcode_func == push && !(is_number(opcode[1])))
			fclose(file);
		if (!opcode_func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode[0]);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		opcode_func(&stack, line_number), line_number++;
		free_opcode(opcode), opcode = NULL;
	}
	fclose(file), free_stack(stack);
	return (0);
}
