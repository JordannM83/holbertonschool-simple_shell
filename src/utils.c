#include "shell.h"

/**
 * Read a line of input from the user.
 * This function reads a line of text from standard input.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	shell_exit(line, nread);
	return (line);
}
