#include "shell.h"

/**
 * Exit the shell.
 * This function terminates the shell process.
 */

void shell_exit(char *line, ssize_t nread)
{
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

	line[strcspn(line, "\n")] = '\0';
	if (strcmp(line, "exit") == 0)
	{
		printf("exit\n");
		free(line);
		exit(0);
	}
}
