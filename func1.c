#include "monty.h"

/**
 * sub - sub the top number
 * @stack: the stack
 * @count: the line counter
 */

void sub(stack_t **stack, unsigned int count)
{
	if (*stack && (*stack)->prev)
	{
		(*stack)->prev->n -= (*stack)->n;
		pop(stack, count);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * _div - div the top number
 * @stack: the stack
 * @count: the line counter
 */

void _div(stack_t **stack, unsigned int count)
{
	if (*stack && (*stack)->prev)
	{
		if ((*stack)->n)
		{
			(*stack)->prev->n /= (*stack)->n;
			pop(stack, count);
		}
		else
		{
			fprintf(stderr, "L%d: division by zero\n", count);
			_exit_(*stack, EXIT_FAILURE, 1);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * mul - mul the top number
 * @stack: the stack
 * @count: the line counter
 */

void mul(stack_t **stack, unsigned int count)
{
	if (*stack && (*stack)->prev)
	{
		(*stack)->prev->n *= (*stack)->n;
		pop(stack, count);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * mod - mod the top number
 * @stack: the stack
 * @count: the line counter
 */

void mod(stack_t **stack, unsigned int count)
{
	if (*stack && (*stack)->prev)
	{
		if ((*stack)->n)
		{
			(*stack)->prev->n %= (*stack)->n;
			pop(stack, count);
		}
		else
		{
			fprintf(stderr, "L%d: division by zero\n", count);
			_exit_(*stack, EXIT_FAILURE, 1);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * push_queue - push_queue
 * @stack: the stack
 * @newNode: the newNode
 *
 * Return: 1 or 0
 */
int push_queue(stack_t **stack, stack_t *newNode)
{
	stack_t *current = *stack;

	if (!args.flag)
	return (0);
	while (current->prev)
		current = current->prev;
	current->prev = newNode;
	newNode->next = current;
	return (1);
}
