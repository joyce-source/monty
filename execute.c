#include "monty.h"
#include "global.h"

/**
 * execute_opcode - execute the instruction based on opcode
 * @opcode: opcode to execute
 * @head: pointer to the head of the stack
 * @line_number: line number of the instruction in the file
 */
void execute_opcode(char *opcode, stack_t **head, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub",_sub},
		{NULL, NULL}
	};
	int i;

	/* Find the opcode in the list of supported opcodes */
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			/* Call the function for the opcode */
			opcodes[i].f(head, line_number);
			break;
		}
	}
	/* Check if the file contains an invalid instruction */
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
