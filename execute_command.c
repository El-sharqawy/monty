#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* execute_command - execute the user command as opcode.
* @input: an input content to be used.
* @head: a pointer to the pointer of the stack_t linked list.
* @n: an input counter.
* @file: an input pointer to monty file.
*
* Return: 1 on Success, otherwise 0.
*/
int32_t execute_command(char *input, stack_t **head, uint32_t n, FILE *file)
{
	uint32_t i = 0;
	char *str;
	instruction_t ops_t[] = {
		{"push", _push}, {"pop", _pop}, {"pall", _pall},
		{"pint", _pint}, {"swap", _swap}, {"add", _add},
		{NULL, NULL}
	};

	str = strtok(input, " \n\t");
	if (str != NULL && str[0] == '#')
		return (0);
	myStack.arg = strtok(NULL, " \n\t");
	while (ops_t[i].opcode && str != NULL)
	{
		if (strcmp(str, ops_t[i].opcode) == 0)
		{
			ops_t[i].f(head, n);
			return (0);
		}
		i++;
	}
	if (str && ops_t[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n, str);
		fclose(file);
		free_tStack(*head);
		free(input);
		exit(EXIT_FAILURE);
	}
	return (1);
}
