#include "monty.h"

/**
 * check_num - check string for valid number
 * @str: string to check
 * @num: the converted int
 * Return: (1) for valid number or (0)
 */
int check_num(const char *str, int *num)
{
	int i = 0;
	int sign = 1;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	*num = atoi(str) * sign;

	return (1);
}
