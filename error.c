#include "shell.h"

/**
 * print_error - Print error message
 * @program_name: Name of the shell program
 * @command: Command that failed
 * @line_count: Line number where error occurred
 * @msg: error message
 */

void print_error(char *program_name, char *command, int line_count, char *msg)
{
	fprintf(stderr, "%s: %d: %s: %s\n",
		program_name, line_count, command, msg);
}
