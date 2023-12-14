#include "monty.h"
stack_t *head = NULL;

/**
 * main - the entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_or(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes
 */
void free_nodes(void)
{
	stack_t *current;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @newnode: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **newnode, __attribute__((unused))unsigned int ln)
{
	stack_t *current;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = *newnode;
	(*newnode)->prev = current;

}
