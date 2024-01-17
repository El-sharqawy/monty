#include "monty.h"

/**
 * free_stack - free a doubly linked list from memory.
 * @head: pointer to the head of the list.
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

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
		push_stack(head, line_num);
	else if (!strcmp(op, "pall"))
		pall_stack(head);
	else if (!strcmp(op, "pint"))
		pint_stack(head, line_num);
	else if (!strcmp(op, "add"))
		add_stack(head, line_num);
	else if (!strcmp(op, "pop"))
		pop_stack(head, line_num);
	else if (!strcmp(op, "nop"))
		nop_stack(head);
	else if (!strcmp(op, "swap"))
		swap_stack(head, line_num);
	else
	{
		fprintf(stderr, "L%u: unknown instruction: %s\n", *line_num, op);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
* push_stack - add node to the linked list.
* @head: a pointer to pointer of struct stack_t linked list.
* @line_num: the input line number pointer
*
* Return: void
*/
void push_stack(stack_t **head, uint32_t *line_num)
{
	int val;
	char *val_str;
	stack_t *newNode;

	val_str = strtok(NULL, " \t\n");
	if (is_integer(val_str) == 0 || val_str == NULL)
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
 * pop_stack - remove element of the stack_t list
 * @head: a pointer points to the stack_t head.
 * @line_num: pointer to a line number.
 *
 * Return: void
 */
void pop_stack(stack_t **head, uint32_t *line_num)
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
 * pall_stack - print the elements of my stackt_t list
 * @head: a pointer points to the stack_t head.
 *
 * Return: void.
 */
void pall_stack(stack_t **head)
{
	stack_t *myNode;

	myNode = *head;
	while (myNode != NULL)
	{
		printf("%d\n", myNode->n);
		myNode = myNode->next;
	}
}

