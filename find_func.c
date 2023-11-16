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
		{"swap", swap_node},
		{"add", add_node},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			cal_fun(func_list[j].f, opcode, val, l_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, l_number, opcode);
}
