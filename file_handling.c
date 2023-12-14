#include "monty.h"

/**
 * open_file - opens a file
 * @file_path: the file path
 * Return: void
 */

void open_file(char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (file_path == NULL || file == NULL)
		err_or(2, file_path);

	read_file(file);
	fclose(file);
}


/**
 * read_file - reads a file
 * @file: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *file)
{
	int line_number, form = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, file) != -1; line_number++)
	{
		form = parse_line(buffer, line_number, form);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens
 * @buffer: line from the file
 * @line_num: line number
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_num, int form)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err_or(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (form);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_num, form);
	return (form);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * @line_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int line_num, int form)
{
	int j;
	int flg;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swaping_nd},
		{"add", addition_nd},
		{"sub", subtract_nd},
		{"div", div_nodes},
		{"mul", multiblie_nd},
		{"mod", mod_nd},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rot_first_tobott},
		{"rotr", rot_last_totop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_fun(func_list[j].f, opcode, value, line_num, form);
			flg = 0;
		}
	}
	if (flg == 1)
		err_or(3, line_num, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @value: string representing a numeric value.
 * @ln: line number for the instruction.
 * @form: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *opcode, char *value, int ln,
		int form)
{
	stack_t *node;
	int flg;
	int j;

	flg = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flg = -1;
		}
		if (value == NULL)
			err_or(5, ln);
		for (j = 0; value[j] != '\0'; j++)
		{
			if (isdigit(value[j]) == 0)
				err_or(5, ln);
		}
		node = create_node(atoi(value) * flg);
		if (form == 0)
			func(&node, ln);
		if (form == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
