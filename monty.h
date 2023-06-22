#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct para - arguments
 * @file: pointer to the file
 * @line: the line
 * @flag: flag
 * Description: carries values through the program
 */
typedef struct para
{
	FILE *file;
	char *line;
	int flag;
} para;
extern para args;

void spec(stack_t **stack, unsigned int count);
stack_t *create_node(stack_t *stack, int data);
void _exit_(stack_t *stack, int val, int order);
void push(stack_t **stack, unsigned int count);
void pall(stack_t **stack, unsigned int count);
void pint(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int count);
void swap(stack_t **stack, unsigned int count);
void add(stack_t **stack, unsigned int count);

#endif
