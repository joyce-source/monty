#include "monty.h"
#include "global.h"
mat_t mat;

/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	ssize_t file_read;
	size_t input_size = 0;
	char *opcode;
	stack_t *struct = NULL;
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	int i;

	/* we are checking to see if arg is 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	mat.file = fopen (argv[1], "r");
	if (mat.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	/* read input file */
	file_read = getline(&mat.line, &input_size, mat.file);
	while (file_read != -1)
	{
		if (*mat.line == '\n')
			continue;
		/* Split the line into opcode and argument */
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		/* Ignore blank lines */
		if (opcode == NULL || *opcode == '#')
			continue;

		/* Find the opcode in the list of supported opcodes */
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				/* Call the function for the opcode */
				opcodes[i].f(&stack, line_number);
				break;
			}
		}

		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
