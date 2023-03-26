#include "monty.h"
/**
	*_pop - node that removes from the stack
	*@head: the pointer is to the stack
	*@line_number: the line that is acessed
	*/

void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	/* check if list is empty */
	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Get a reference to the current first node*/
	temp = *head;
	/* Update head pointer to point to the next node*/
	*head = temp->next;
	/* Update prev pointer of the new first node to NULL*/
		if (*head != NULL)
			(*head)->prev = NULL;
	/*free memory for the old first node*/
	free(*head);
}
