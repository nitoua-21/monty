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
