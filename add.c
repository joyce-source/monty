#include "monty.h"

/**
  *_add - adds top two , stores then frees memory by removing the top element
  *@head: this is the pointer to the stack head
  *@line_number: line number to the monty file
  */

void _add(stack_t **head, unsigned int line_number)
{
	int sum;

	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;
	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	free(temp);
}

