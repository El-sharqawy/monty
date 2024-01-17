#include "monty.h"
#include <stdlib.h>

/**
* _push - add node to the linked list.
* @head: a pointer to pointer of struct stack_t linked list.
* @count: the input number
*
* Return: void
*/
void _push(stack_t **head, uint32_t count)
{
	int32_t num;
	int32_t i = 0, f = 0;

	if (myStack.arg != NULL)
	{
		if (myStack.arg[0] == '-')
			i++;
		for (; myStack.arg[i] != '\0'; i++)
		{
			if (myStack.arg[i] < 48 || myStack.arg[i] > 57)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(myStack.filename);
			free(myStack.input);
			free_tStack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(myStack.filename);
		free(myStack.input);
		free_tStack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(myStack.arg);
	if (myStack.flag == 0)
	{
		add_node(head, num);
	}
	else
	{
		add_queue(head, num);
	}
}

/**
* add_node - add node to the doubly linked list at the head of the stack.
* @head: a pointer to pointer that points to the head of the list.
* @count: a node value.
* Return: void
*/
void add_node(stack_t **head, uint32_t count)
{
	stack_t *myNode;
	stack_t *temp;

	temp = *head;
	myNode = malloc(sizeof(stack_t));
	if (myNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp != NULL)
		temp->prev = myNode;

	myNode->n = count;
	myNode->next = *head;
	myNode->prev = NULL;
	*head = myNode;
}

/**
* add_queue - add node to the doubly linked list at the tail of the stack.
* @head: a pointer to pointer that points to the head of the list.
* @count: a node value.
* Return: void
*/
void add_queue(stack_t **head, uint32_t count)
{
	stack_t *myNode;
	stack_t *temp;

	temp = *head;
	myNode = malloc(sizeof(stack_t));
	if (myNode == NULL)
	{
		printf("Error\n");
	}
	myNode->n = count;
	myNode->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = myNode;
		myNode->prev = NULL;
	}
	else
	{
		temp->next = myNode;
		myNode->prev = temp;
	}
}
