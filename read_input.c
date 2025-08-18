#include "shell.h"

/**
 * read_command - Read command from user input
 * Return: Command string or NULL on EOF
 */

char *read_command(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;

	nread = getline(&line, &size, stdin);
	if (nread == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}

	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	shell_exit(line, nread);
	return (line);
}
