#include "monty.h"

/**
  *_add - adds top two , stores then frees memory by removing the top element
  *@head: this is the pointer to the stack head
  *@line_number: line number to the monty file
  */

void _add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	_pop(head, line_number);

}

