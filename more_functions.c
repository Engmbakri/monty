#include "monty.h"

/**
 * multiblie_nd - multiblies  the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lnum: Interger representing the line number of of the opcode.
 */
void multiblie_nd(stack_t **stack, unsigned int lnum)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		another_err(8, lnum, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nd - mods the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void mod_nd(stack_t **stack, unsigned int linenumber)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		another_err(8, linenumber, "mod");


	if ((*stack)->n == 0)
		another_err(9, linenumber);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
