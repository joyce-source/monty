#include "monty.h"
#include "global.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int n;

	if (arg == NULL || ((!isdigit(*arg) && *arg != '-') && strlen(arg) > 1))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		 new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: pointer to the stack
 * @line_number: line number in the Monty file
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
