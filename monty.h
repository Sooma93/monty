#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#define _POSIX_C_SOURCE200809L
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
typedef void (*op_fun)(stack_t **, unsigned int);
void read_file(FILE *f);
void find_func(char *opcode, char *val, int l_number, int format);
void open_file(char *f_name);
int parse_line(char *buffer, int l_number, int format);
void error(int err_code, ...);
void more_error(int error_code, ...);
void call_fun(op_fun func, char *op, char *val, int ln, int format);

/** stack **/
void add_to_stack(stack_t **new, __attribute__((unused))unsigned int ln);
void print_stack(stack_t **stack, unsigned int line_num);
void pop_top(stack_t **stack, unsigned int line_numb);
void print_top(stack_t **stack, unsigned int line_numb);
void div_nodes(stack_t **stack, unsigned int line_numb);
void nop(stack_t **stack, unsigned int line_numb);
void swap_nodes(stack_t **stack, unsigned int line_numb);
void sub_nodes(stack_t **stack, unsigned int line_numb);
void add_nodes(stack_t **stack, unsigned int line_numb);
void free_nodes(void);
void add_to_queue(stack_t **, unsigned int);
stack_t *create_node(int num);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line);
int main(int argc, char *argv[]);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void mul_nodes(stack_t **stack, unsigned int l_number);
void mod_nodes(stack_t **stack, unsigned int l_number);





#endif
