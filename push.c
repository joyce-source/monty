#include "monty.h"
#include "global.h"

/**
 * _push - add node to the head
 * @head: pointer to head head
 * @line_number: the line number  in the monty file
 * Return: no return
*/
void _push(stack_t **head, unsigned int line_number)
{
	int new_n;
	stack_t *new_node;
	/*printf("arg2: %s\n", mat.arg);*/
	/* we are checking if the agr is given */
	/* if the arg is not a digit*/
	if (mat.arg == NULL || !is_number(mat.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*we are converting agr to digits */
	new_n = atoi(mat.arg);
	/* Allocate memory for new node */
	new_node = malloc(sizeof(stack_t));
	/*check if we cant allocate memory*/
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Set data for new node */
	/* Set prev pointer for new node */
	/* Set next pointer for new node to the current top node */
	new_node->n = new_n;
	new_node->prev = NULL;
	new_node->next = *head;
	/* update prev pointer of the current first node */
	if (*head != NULL)
		(*head)->prev = new_node;
	/* update head pointer to point to new node */
	*head = new_node;
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
