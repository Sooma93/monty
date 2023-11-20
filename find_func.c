#include "monty.h"
/**
 * find_func - find the function
 * @opcode: opertion code
 * @val: value of code
 * @format: strage
 * @l_number: line number
 * Return: void
 */

void find_func(char *opcode, char *val, int l_number, int format)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_fun(func_list[j].f, opcode, val, l_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, l_number, opcode);
}
/**
 * call_fun - call
 * @func: pointer
 * @op: operation
 * @val: string
 * @ln: line number
 * @format: format
 */
void call_fun(op_fun func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
		val = val + 1;
		flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = (create_node(atoi(val) * flag));
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
