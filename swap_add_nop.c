#include "monty.h"

/**
 * swap - swap top 2 elements of stack
 * @stack: pointer to stack
 * @line_number: line number in file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_top = *stack;
	stack_t *nxt;

	if (stack_top == NULL || stack_top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	nxt = stack_top->next;

	stack_top->prev = nxt;
	stack_top->next = nxt->next;
	nxt->prev = NULL;

	if (nxt->next != NULL)
		nxt->next->prev = stack_top;
	nxt->next = stack_top;
	*stack = nxt;
}

/**
 * nop - function that does nothing
 * @stack: pointer to stack
 * @line_number: line number in file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
