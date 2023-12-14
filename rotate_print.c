#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii_code;

	if (stack == NULL || *stack == NULL)
		str_err(11, line_number);

	ascii_code = (*stack)->n;
	if (ascii_code < 0 || ascii_code > 127)
		str_err(10, line_number);
	printf("%c\n", ascii_code);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	current = *stack;
	while (current != NULL)
	{
		ascii = current->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot_first_tobott(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rot_last_totop - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot_last_totop(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	current->next = *stack;
	current->prev->next = NULL;
	current->prev = NULL;
	(*stack)->prev = current;
	(*stack) = current;
}
