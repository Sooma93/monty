#include "monty.h"
/**
 * pop_top - add node
 * @stack: pointer
 * @line_numb: line number
 */
void pop_top(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_error(7, line_numb);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * print_top - the top node
 * @stack: pointer
 * @line_numb: line number
 */
void print_top(stack_t **stack, unsigned int line_numb)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, line_numb);
	printf("%d\n", (*stack)->n);
}
/**
 * div_nodes - divid node
 * @stack: pointer
 * @line_numb: line number
 */
void div_nodes(stack_t **stack, unsigned int line_numb)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_numb, "div");

	if ((*stack)->n == 0)
		more_error(9, line_numb);
	(*stack) = (*stack)->next;
	num = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - nothing
 * @stack: pointer
 * @line_numb: line number
 */
void nop(stack_t **stack, unsigned int line_numb)
{
	(void)stack;
	(void)line_numb;
}
/**
 * swap_nodes - swap
 * @stack: pointer
 * @line_numb: line number
 */
void swap_nodes(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_numb, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * sub_nodes - sub node
 * @stack: pointer
 * @line_numb: line number
 */
void sub_nodes(stack_t **stack, unsigned int line_numb)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_numb, "sub");
	(*stack) = (*stack)->next;
	num = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * add_nodes - add node
 * @stack: pointer
 * @line_numb: line number
 */
void add_nodes(stack_t **stack, unsigned int line_numb)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, line_numb, "add");
	(*stack) = (*stack)->next;
	num = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
