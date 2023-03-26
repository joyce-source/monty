#include "monty.h"
/**
  *_pop - node that removes from the stack
  *@head: the pointer is to the stack
  *@line_number: the line that is acessed
  */

void _pop(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)--;
}

