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
	unsigned int line_number = 0;
	char *opcode;
	stack_t *head = NULL;
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};
	int i;

	/* Check if there is more than one argument no file given */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Check if the file can be opend */
	mat.file = fopen (argv[1], "r");
	if (mat.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	/* read input monty file */
	while ((file_read = getline(&mat.line_input, &input_size, mat.file)) != -1)
	{
		line_number++;

		/* Split the line into opcode and argument */
		opcode = strtok(mat.line_input, " \t\n");
		mat.arg = strtok(NULL, " \t\n");
		/*debug prints*/
		/*printf("opcode: %s\n", opcode);*/
		/*printf("arg: %s\n", mat.arg);*/

		/* Ignore blank lines & Commnets*/
		if (opcode == NULL || *opcode == '#')
			continue;

		/* Find the opcode in the list of supported opcodes */
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				/* Call the function for the opcode */
				opcodes[i].f(&head, line_number);
				break;
			}
		}
		/* Check if the file contains an invalid instruction */
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(mat.line_input);
	fclose(mat.file);
	exit(EXIT_SUCCESS);
}
