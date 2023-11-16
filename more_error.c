#include "monty.h"

/**
 * more_error - handle error
 * @error_code: the error code
 */
void more_error(int error_code, ...)
{
	va_list ag;
	char *op;
	int i_number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: : can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			i_number = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", i_number, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
