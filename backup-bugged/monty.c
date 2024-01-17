#include "monty.h"

/**
* main - Entry point.
* @argc: number of arguments passed to the program.
* @argv: an input argument. (monty file)
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	FILE *filename;
	char *input = NULL, *op;
	stack_t *stack;
	uint32_t line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = fopen(argv[1], "r");
	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	input = (char *)malloc(256);
	if (input == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(input, 256, filename) != NULL)
	{
		op = strtok(input, " \t\n");
		if (op != NULL && strcmp(op, "#") != 0)
		{
			execute_command(op, &stack, &line_num);
		}
		line_num++;
	}
	fclose(filename);
	free(input);
	free_tStack(stack);
	return (EXIT_SUCCESS);
}
