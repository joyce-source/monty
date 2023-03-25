#include "monty.h"
#include "global.h"

/**
 * _push - add node to the stack
 * @head: pointer to stack head
 * @line_number: the line number  in the monty file
 * Return: no return
*/
void _push(stack_t **head, unsigned int line_number)
{
	int number;
	stack_t *new_node;
	/*printf("arg2: %s\n", mat.arg);*/
	/* we are checking if the agr is given */
	/* if the arg is not a digit*/
	if (mat.arg == NULL || !isdigit(*mat.arg))
	{
		fprintf(stderr, "L%u: usage push interger\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*we are converting agr to digits */
	number = atoi(mat.arg);
	/*printf("arg3: %d\n", number);*/

	new_node = malloc(sizeof(stack_t));

	/*check if we cant allocate memory*/
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*we are addeing the new number to the stack*/
	new_node->n = number;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
}
