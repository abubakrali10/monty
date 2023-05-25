#include "monty.h"

/**
 * free_stack - free momory for stack
 * @stack: the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *nxt;

	while (curr != NULL)
	{
		nxt = curr->next;
		free(curr);
		curr = nxt;
	}
	*stack = NULL;
}
