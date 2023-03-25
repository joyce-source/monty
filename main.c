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
	stack_t *head = NULL;
	ssize_t file_read;
	size_t input_size = 0;
	unsigned int line_number = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mat.file = fopen(argv[1], "r");
	if (mat.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	while ((file_read = getline(&mat.line_input, &input_size, mat.file)) != -1)
	{
		line_number++;
		opcode = strtok(mat.line_input, " \t\n");
		mat.arg = strtok(NULL, " \t\n");
		if (opcode == NULL || *opcode == '#')
			continue;
		execute_opcode(opcode, &head, line_number);
	}

	free_stack(head);
	free(mat.line_input);
	fclose(mat.file);
	exit(EXIT_SUCCESS);
}
