#include "shell.h"

/**
 * print_error - prints an error message to stderr
 * @msg: the error message to print
 */

void print_error(const char *msg)
{
	perror(msg);
}
