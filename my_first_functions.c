#include "monty.h"

/**
* execute_command - execute the user command as opcode.
* @op: an input content to be used.
* @head: a pointer to the pointer of the stack_t linked list.
* @line_num: an input line number.
*
* Return: void.
*/
void execute_command(char *op, stack_t **head, uint32_t *line_num)
{
	if (!strcmp(op, "push"))
		_push(head, line_num);
	else if (!strcmp(op, "pall"))
		_pall(head);
	else if (!strcmp(op, "pint"))
		_pint(head, line_num);
	else if (!strcmp(op, "add"))
		_add(head, line_num);
	else if (!strcmp(op, "pop"))
		_pop(head, line_num);
	else if (!strcmp(op, "nop"))
		_nop(head);
	else if (!strcmp(op, "swap"))
		_swap(head, line_num);
	else
	{
		fprintf(stderr, "L%u: unknown instruction: %s\n", *line_num, op);
		free_tStack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
* _push - add node to the linked list.
* @head: a pointer to pointer of struct stack_t linked list.
* @line_num: the input line number pointer
*
* Return: void
*/
void _push(stack_t **head, uint32_t *line_num)
{
	int32_t val;
	char *val_str;
	stack_t *newNode;

	val_str = strtok(NULL, " \t\n");
	if (is_int(val_str) == 0 || val_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", *line_num);
		exit(EXIT_FAILURE);
	}
	val = atoi(val_str);
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = val;
	newNode->prev = NULL;
	newNode->next = *head;
	if ((*head) != NULL)
		(*head)->prev = newNode;
	*head = newNode;
}

/**
 * _pop - remove element of the stack_t list
 * @head: a pointer points to the stack_t head.
 * @line_num: pointer to a line number.
 *
 * Return: void
 */
void _pop(stack_t **head, uint32_t *line_num)
{
	stack_t *myNode;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", *line_num);
		exit(EXIT_FAILURE);
	}
	myNode = *head;
	*head = (*head)->next;
	if ((*head) != NULL)
		(*head)->prev = NULL;
	free(myNode);
}

/**
 * _pall - print the elements of my stackt_t list
 * @head: a pointer points to the stack_t head.
 *
 * Return: void.
 */
void _pall(stack_t **head)
{
	stack_t *myNode;

	myNode = *head;
	while (myNode != NULL)
	{
		printf("%d\n", myNode->n);
		myNode = myNode->next;
	}
}

/**
 * _pint - print element at the top of the stack_t list.
 * @head: a pointer points to the stack_t head.
 * @line_num: a pointer to the line number
 *
 * Return: void
 */
void _pint(stack_t **head, uint32_t *line_num)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", *line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
