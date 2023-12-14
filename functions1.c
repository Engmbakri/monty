#include "monty.h"


/**
 * adding_tostack - Adds a node to the stack.
 * @newnode: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void adding_tostack(stack_t **newnode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	tmp = head;
	head = *newnode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * printstack - prints the integer value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void printstack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop_element - pops an element from  a node.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void pop_element(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		another_err(7, line_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * top_print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void top_print(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		another_err(6, line_num);
	printf("%d\n", (*stack)->n);
}
