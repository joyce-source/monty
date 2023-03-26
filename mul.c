#include "monty.h"
/**
  *_mul - muiltiply the number then frees the memory
  *@head: pointer to the stack
  *@line_number: line to the monty file
  */

void _mul(stack_t **head, unsigned int line_number)
{
	int a;

	int b;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*head)->n;
	b = (*head)->next->n;
	(*head)->next->n = b * a;
	_pop(head, line_number);
}

