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
