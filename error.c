#include "shell.h"

/**
 * print_error - Print error message
 * @program_name: Name of the shell program
 * @command: Command that failed
 * @line_count: Line number where error occurred
 */

void print_error(char *program_name, char *command, int line_count)
{
	fprintf(stderr, "%s: %d: %s: not found\n",
		program_name, line_count, command);
}
