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
	char *input = NULL;
	size_t size = 0;
	stack_t *stack;
	ssize_t line = 1;
	uint32_t count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = fopen(argv[1], "r");

	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	myStack.filename = filename;

	while (line > 0)
	{
		line = getline(&input, &size, filename);
		myStack.input = input;
		count++;
		if (line > 0)
			execute_command(input, &stack, count, filename);
		free(input);
	}
	free_tStack(stack);
	fclose(filename);
	return (0);
}
