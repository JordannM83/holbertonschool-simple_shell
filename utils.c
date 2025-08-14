#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 * Return: A pointer to the input string or NULL on failure.
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
