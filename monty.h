#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define uint32_t unsigned int
#define BUFFER_SIZE 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
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
	void (*f)(stack_t **stack);
} instruction_t;

extern stack_t *head;
extern uint32_t line_number;

void push_stack(stack_t **head, uint32_t *line_num);
void pall_stack(stack_t **head);
void pint_stack(stack_t **head, uint32_t *line_num);
void pop_stack(stack_t **head, uint32_t *line_num);
void swap_stack(stack_t **head, uint32_t *line_num);
void add_stack(stack_t **head, uint32_t *line_num);
void nop_stack(stack_t **head);
void execute_command(char *opcode, stack_t **head, uint32_t *line_num);
int is_integer(const char *str);
void free_stack(stack_t *head);

#endif /* MONTY_H */
