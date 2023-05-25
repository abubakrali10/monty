#include "monty.h"

/**
 * pint - prints the value at the top of stack
 * @stack: pointer to stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element from stack
 * @stack: pointer to stack
 * @line_number: line number in file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ptr);
}
