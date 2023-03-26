#include "monty.h"

/**
  *_div - divides 2 numbers then frees memory
  *@head: the pointer that points to the stack
  *@line_number: line number in the monty file
  */
void _div(stack_t **head, unsigned int line_number)
{
	int a;

	int b;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*head)->n;
	b = (*head)->next->n;

	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = b / a;
	_pop(head, line_number);
}

