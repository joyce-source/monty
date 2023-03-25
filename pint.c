#include "monty.h"

/**
 * _pint - prints  the value on top of the stack
 * @head: pointer to stack head
 * @line_number: number in the monty file
 * Return: no return
*/
void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
