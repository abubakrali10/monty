#include "monty.h"

/**
 * check_opcode - get monty instraction
 * @opcode: opcode
 * Return: a pointer to instruction_t or NULL if opcode not found
 */

instruction_t *check_opcode(char *opcode)
{
	int i = 0;
	instruction_t *instruction = NULL;
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};

	while (op_codes[i].opcode != NULL)
	{
		if (strcmp(opcode, op_codes[i].opcode) == 0)
		{
			instruction = malloc(sizeof(instruction_t));

			if (instruction == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			memcpy(instruction, &op_codes[i], sizeof(instruction_t));
			break;
		}
		i++;
	}
	return (instruction);
}
