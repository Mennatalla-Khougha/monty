#include "monty.h"

para args = {NULL, NULL, 0};
/**
* create_node - create new node
* @data: node element
* @stack: the stack
* Return: a new node
*/
stack_t *create_node(stack_t *stack, int data)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_exit_(stack, EXIT_FAILURE, 1);
	}
	node->n = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/**
* push - push a new node
 * @stack: the stack
 * @count: the line counter
*/
void push(stack_t **stack, unsigned int count)
{
	stack_t *newNode;
	int i = 0;
	char *num;

	(void)count;

	num = strtok(NULL, " \n\t");
	if (!num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		_exit_(*stack, EXIT_FAILURE, 1);
	}
	else
	{
		if (num[i] == '-')
			i++;
		while (num[i])
		{
			if (num[i] < 48 || num[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", count);
				_exit_(*stack, EXIT_FAILURE, 1);
			}
			i++;
		}
	}
	newNode = create_node(*stack, atoi(num));

	if (*stack == NULL)
		*stack = newNode;
	else
	{
		if (push_queue(stack, newNode))
			return;
		newNode->prev = *stack;
		(*stack)->next = newNode;
		*stack = newNode;
	}
}

/**
 * pall - print the list
 * @stack: the stack
 * @count: the line counter
 */
void pall(stack_t **stack, unsigned int count)
{
	stack_t *print = *stack;

	(void)count;

	while (print)
	{
		printf("%d\n", print->n);
		print = print->prev;
	}
}

/**
 * _exit_ - free the stack and exit.
 * @stack: the stack
 * @val: the return value
 * @order: flag to close or not close
 */

void _exit_(stack_t *stack, int val, int order)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->prev;
		free(stack);
		stack = tmp;
	}
	free(args.line);
	if (order)
		fclose(args.file);
	exit(val);
}

/**
 * main - the main function
 * @argc: the number of arguments
 * @argv: the command line argument
 * Return: 0;
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	unsigned int count = 0;
	ssize_t buffer = 1;
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		_exit_(stack, EXIT_FAILURE, 0);
	}
	args.file = fopen(argv[1], "r");
	if (!args.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		_exit_(stack, EXIT_FAILURE, 0);
	}
	while (buffer > 0)
	{
		buffer = getline(&args.line, &n, args.file);
		count++;
		if (buffer > 0)
			spec(&stack, count);
	}
	_exit_(stack, 0, 1);
	return (0);
}
