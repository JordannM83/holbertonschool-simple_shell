#include "shell.h"

/**
 * Print an error message to stderr.
 * This function displays an error message to the standard error output.
 */

void print_error(const char *msg)
{
	perror(msg);
}
