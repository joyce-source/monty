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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Set temp to point to the next node in the stack */
	temp = (*head)->next;
	/*Free the memory allocated for the current top node of the stack*/
	free(*head);
	/*Update the head pointer to point to the new top node.*/
	*head = temp;
	/*Update the prev pointer of the new top node to NULL*/
	/*to indicate that it is now the top of the stack.*/
 if (*head != NULL)
		(*head)->prev = NULL;
}
