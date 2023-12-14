#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(char *file_path);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *file);
int len_chars(FILE *);
void find_func(char *opcode, char *value, int line_number, int format);

stack_t *create_node(int n);
void free_nodes(void);
void printstack(stack_t **, unsigned int);
void adding_tostack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void top_print(stack_t **, unsigned int);
void pop_element(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swaping_nd(stack_t **, unsigned int);

void addition_nd(stack_t **, unsigned int);
void subtract_nd(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void multiblie_nd(stack_t **, unsigned int);
void mod_nd(stack_t **, unsigned int);

void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rot_first_tobott(stack_t **, unsigned int);

void err_or(int error_type, ...);
void another_err(int error_type, ...);
void str_err(int error_type, ...);
void rot_last_totop(stack_t **, unsigned int);

#endif
