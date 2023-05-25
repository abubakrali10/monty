#include "monty.h"

void free_memory(FILE *f, char *line, stack_t **stack);

/**
 * main - start of the monty interpreter
 * @argc: command-line arguments count
 * @argv: command-line arguments array
 * Return: (0) for success OR (exit_failure) for failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t line_len = 0;
	stack_t *stack = NULL;
	char *line = NULL;
	unsigned int line_num = 0;
	char *op_code;
	instruction_t *instruction = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_len, fp) != -1)
	{
		line_num++;
		op_code = strtok(line, " \t\n");

		if (op_code == NULL || op_code[0] == '#')
			continue;
		instruction = check_opcode(op_code);

		if (instruction)
		{
			instruction->f(&stack, line_num);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, op_code);
			free_memory(fp, line, &stack);
			exit(EXIT_FAILURE);
		}
	}
	free_memory(fp, line, &stack);
	return (0);
}

/**
 * free_memory - free alocated memory
 * @f: pointer to file
 * @line: pointer to the line
 * @stack: pointer to stack
 */
void free_memory(FILE *f, char *line, stack_t **stack)
{
	free(line);
	free_stack(stack);
	fclose(f);
}
