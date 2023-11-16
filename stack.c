#include "monty.h"
/**
 * add_to_stack - add node
 * @new: pointer
 * @ln: line number
 */
void add_to_stack(stack_t **new, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	head = *new;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * print_stack - add node
 * @stack: pointer to pointer
 * @line_num: line number
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
