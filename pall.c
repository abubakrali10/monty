#include "monty.h"

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
