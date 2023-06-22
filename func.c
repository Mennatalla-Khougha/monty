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
				{NULL, NULL}
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

