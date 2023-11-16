#include "monty.h"
/**
 * open_file - open file
 * @f_name: name of file
 * Return: void
 */
void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		error(2, f_name);
	read_file(fd);
	fclose(fd);
}
/**
 * read_file - read file
 * @fd: pointer
 * Return: void
 */
void read_file(FILE *fd)
{
	int l_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;
	for (l_number = 1; getline(&buffer, &len, fd) != -1; l_number++)
	{
		format = parse_line(buffer, l_number, format);
	}
	free(buffer);
}
/**
 * parse_line - sperate line
 * @buffer: line
 * @l_number: line number
 * @format: storage
 * Return: 0 or 1
 */
int parse_line(char *buffer, int l_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, val, l_number, format);
	return (format);
}
