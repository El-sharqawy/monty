#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define uint32_t unsigned int
#define int32_t int

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: an integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct SMyStack - struct for my program architecture.
* @arg: an argument passed to the struct.
* @filename: pointer to monty file.
* @input: an input content.
* @flag: flag to change the stack/queue.
*
* Description: a struct that carries and pas the values through our program.
*/
typedef struct SMyStack
{
	char *arg;
	FILE *filename;
	char *input;
	int flag;
} TMyStack;

extern TMyStack myStack;

int32_t execute_command(char *input, stack_t **head, uint32_t n, FILE *file);
void free_tStack(stack_t *head);
void _push(stack_t **head, uint32_t count);
void _pop(stack_t **head, uint32_t count);
void _pall(stack_t **head, uint32_t count);
void _pint(stack_t **head, uint32_t count);
void _swap(stack_t **head, uint32_t count);
void _add(stack_t **head, uint32_t count);

void add_node(stack_t **head, uint32_t count);
void add_queue(stack_t **head, uint32_t count);

#endif /* __MONTY_H__ */
