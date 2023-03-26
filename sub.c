#include "monty.h"
/**
  *_sub - subtracts the top of the element then fres memory
  *@head: the pointer to stack
  *line_number: the line number of the monty file
  */

void _sub(stack_t **head, unsigned int line_number)
{
	int a;

	int b;

	if (*head == NULL || (*head)->next == NULL)
    {
	    fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	    exit(EXIT_FAILURE);
    }
	a = (*head)->n;
	b = (*head)->next->n;
	(*head)->next->n = b - a;
	_pop(head, line_number);
}

