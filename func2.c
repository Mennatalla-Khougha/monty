#include "monty.h"

/**
 * pchar - pchar the top number
 * @stack: the stack
 * @count: the line counter
 */

void pchar(stack_t **stack, unsigned int count)
{
	int n;

	if (*stack)
	{
		n = (*stack)->n;
		if (n > -1 && n < 128)
			printf("%c\n", n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
			_exit_(*stack, EXIT_FAILURE, 1);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * pstr - pstr the top number
 * @stack: the stack
 * @count: the line counter
 */

void pstr(stack_t **stack, unsigned int count)
{
	stack_t *str = *stack;
	int n;

	(void)count;

	if (*stack)
	{
		n = str->n;
		while (n > 0 && n < 128 && str->prev)
		{
			printf("%c", n);
			str = str->prev;
			n = str->n;
		}
		if (n > 0 && n < 128)
			printf("%c", n);
	}
	printf("\n");
}

/**
 * rotl - rotl the top number
 * @stack: the stack
 * @count: the line counter
 */

void rotl(stack_t **stack, unsigned int count)
{
	stack_t *current = *stack, *node;

	if (*stack && (*stack)->prev)
	{
		node = create_node(*stack, current->n);
		while (current->prev)
			current = current->prev;
		current->prev = node;
		node->next = current;
		pop(stack, count);
	}
}

/**
 * rotr - rotr the top number
 * @stack: the stack
 * @count: the line counter
 */

void rotr(stack_t **stack, unsigned int count)
{
	stack_t *current = *stack, *node;

	(void)count;

	if (*stack && (*stack)->prev)
	{
		while (current->prev)
			current = current->prev;
		node = create_node(*stack, current->n);
		current->next->prev = NULL;
		free(current);
		(*stack)->next = node;
		node->prev = *stack;
		*stack = node;
	}
}
