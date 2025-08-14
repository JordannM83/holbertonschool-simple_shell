#include "shell.h"

/**
 * Exit the shell.
 * This function terminates the shell process.
 */

void *shell_exit(char *line, ssize_t nread)
{
	char *argc = NULL;

	if (nread == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);
		}
		free(line);
		print_error("Get line error");
		exit(1);
	}
	else if (strcmp(&argc[0], "exit") == 0)
	{
		exit(0);
	}

	return (line);
}
