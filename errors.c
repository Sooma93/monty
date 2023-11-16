#include "monty.h"
/**
 * error - print my error
 * @err_code: explan my error and error message
 */
void error(int err_code, ...)
{
	va_list i;
	char *code;
	int num;

	va_start(i, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, " Error: Can't open file %s\n",
					va_arg(i, char *));
			break;
		case 3:
			num = va_arg(i, int);
			code = va_arg(i, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(i, int));
			break;
default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

