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
