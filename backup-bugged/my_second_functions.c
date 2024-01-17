#include "monty.h"

/**
 * is_int - if it's valid integer.
 * @input: an input string to check.
 *
 * Return: 1 if int, otherwise 0.
 */
int32_t is_int(const char *input)
{
	if (input == NULL)
		return (0);
	if (*input == '\0')
		return (0);

	if (*input == '0')
		input++;

	while (*input != '\0')
	{
		if (isdigit(*input) == 0)
			return (0);
		input++;
	}
	return (1);
}

/**
 * _swap - swap between two elements in the stack_t list
 * @head: a pointer that points to the head of stack_t list
 * @line_num: a pointer to the line number.
 *
 * Return: void
 */
void _swap(stack_t **head, uint32_t *line_num)
{
	int32_t tmp;

	if ((*head)->next == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", *line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}

/**
 * _add - add element to the stackt_t list
 * @head: pointer to the head of the stack_t list
 * @line_num: pointer to line number.
 *
 * Return: void
 */
void _add(stack_t **head, uint32_t *line_num)
{
	stack_t *newNode;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", *line_num);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	newNode = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(newNode);
}

/**
 * _nop - does nothing for now (TODO)
 * @head: a pointer to the head of the stack_t list
 *
 * Return: void.
 */
void _nop(stack_t **head)
{
	(void)head;
}
