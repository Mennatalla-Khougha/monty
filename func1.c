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