#include "monty.h"

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: input arguments
 *
 * Return: Always EXIT_SUCCESS (Success)
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	FILE *filename;
	char *op, *command = NULL;
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
	command = (char *)malloc(BUFFER_SIZE);
	if (command == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(command, BUFFER_SIZE, filename) != NULL)
	{
		op = strtok(command, " \t\n");
		if (op && strcmp(op, "#"))
		{
			execute_command(op, &head, &line_num);
		}
		line_num++;
	}
	free(command);
	free_stack(head);
	fclose(filename);

	return (EXIT_SUCCESS);
}
