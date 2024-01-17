#include "monty.h"

/**
 * pint_stack - print element at the top of the stack_t list.
 * @head: a pointer points to the stack_t head.
 * @line_num: a pointer to the line number
 *
 * Return: void
 */
void pint_stack(stack_t **head, uint32_t *line_num)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", *line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * add_stack - add element to the stackt_t list
 * @head: pointer to the head of the stack_t list
 * @line_num: pointer to line number.
 *
 * Return: void
 */
void add_stack(stack_t **head, uint32_t *line_num)
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
 * swap_stack - swap between two elements in the stack_t list
 * @head: a pointer that points to the head of stack_t list
 * @line_num: a pointer to the line number.
 *
 * Return: void
 */
void swap_stack(stack_t **head, uint32_t *line_num)
{
	int tmp;

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
 * nop_stack - does nothing for now (TODO)
 * @head: a pointer to the head of the stack_t list
 *
 * Return: void.
 */
void nop_stack(stack_t **head)
{
	(void)head;
}

/**
 * is_integer - if it's valid integer.
 * @input: an input string to check.
 *
 * Return: 1 if int, otherwise 0.
 */
int is_integer(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '\0')
		return (0);

	if (*str == '0')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
