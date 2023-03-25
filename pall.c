#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * @head: pointer to stack head
 * @line_number: number in the monty file
 * Return: no return
*/
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
