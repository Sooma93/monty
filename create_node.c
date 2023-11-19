#include "monty.h"

/**
 * create_node - craete node
 * @num: number of nodes
 * Return: NULL
 */

stack_t *create_node(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = num;
	return (node);
}
/**
 * free_nodes - free nodes
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head !=  NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - add to queue
 * @new_node: to the node
 * @line: line number
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
