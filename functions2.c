#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * swaping_nd - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void swaping_nd(stack_t **stack, unsigned int l_n)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		another_err(8, l_n, "swap");
	current = (*stack)->next;
	(*stack)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *stack;
	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}

/**
 * addition_nd - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void addition_nd(stack_t **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		another_err(8, l_n, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * subtract_nd - sub  the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of  the opcode.
 */
void subtract_nd(stack_t **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		another_err(8, l_n, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - divise the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_num)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		another_err(8, line_num, "div");

	if ((*stack)->n == 0)
		another_err(9, line_num);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
