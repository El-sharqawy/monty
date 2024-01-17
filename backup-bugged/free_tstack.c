#include "monty.h"

/**
* free_tStack - free a doubly linked list from memory.
* @head: pointer to the struct stack_t.
*
* Return: void.
*/
void free_tStack(stack_t *head)
{
	stack_t *stack;

	while (head != NULL)
	{
		stack = head;
		head = head->next;
		free(stack);
	}
}
