#include "monty.h"

/**
 * push - pushes element to stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int val;
	char *str_val = strtok(NULL, "\t\n");
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!stack)
	{
		fprintf(stderr, "L%u: Stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!str_val)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!check_num(str_val, &val))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all elements inside the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
