#include "monty.h"

/**
* spec - executes the command
* @stack: the stack
* @count: line counter
*/
void spec(stack_t **stack, unsigned int count)
{
	char *token = NULL;
	int x;
	instruction_t opst[] = {
				{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop}, {"swap", swap}, {"add", add},
				{"sub", sub}, {NULL, NULL}
				};
	unsigned int i = 0;

	token = strtok(args.line, " \n\t");
	if (!token || !strcmp(token, "nop") || token[0] == '#')
		return;
	x = (!strcmp(token, "stack") && args.flag);
	x += (!strcmp(token, "queue") && !args.flag);
	if (x)
	{
		args.flag = !args.flag;
		return;
	}
	while (opst[i].opcode && token)
	{
		if (!strcmp(token, opst[i].opcode))
		{
			opst[i].f(stack, count);
			break;
		}
		i++;
	}
	if (!opst[i].opcode && token)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, token);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * pint - print the top number
 * @stack: the stack
 * @count: the line counter
 */
void pint(stack_t **stack, unsigned int count)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		fclose(args.file);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - deletes the top element
 * @stack: the stack
 * @count: the line counter
 */
void pop(stack_t **stack, unsigned int count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(args.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev)
	{
		*stack = (*stack)->prev;
		free((*stack)->next);
		(*stack)->next = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - swap the top 2 number
 * @stack: the stack
 * @count: the line counter
 */

void swap(stack_t **stack, unsigned int count)
{
	int tmp;

	if (*stack && (*stack)->prev)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->prev->n;
		(*stack)->prev->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}

/**
 * add - add the top 2 number
 * @stack: the stack
 * @count: the line counter
 */

void add(stack_t **stack, unsigned int count)
{
	if (*stack && (*stack)->prev)
	{
		(*stack)->prev->n += (*stack)->n;
		pop(stack, count);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
}
