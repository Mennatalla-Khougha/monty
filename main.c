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
	}
	args.file = fopen(argv[1], "r");
	if (!args.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	}
	while (buffer > 0)
	{
		buffer = getline(&args.line, &n, args.file);
		count++;
		if (buffer > 0)
			spec(&stack, count);
	}
	return (0);
}
