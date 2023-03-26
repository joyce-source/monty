#include "monty.h"
/**
  *_swap - swaps the top two elements of the stack
  *@head: the node on the stack
  *@line_number: line on the monty file
  */
void _swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
