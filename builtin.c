#include "shell.h"

/**
 * shell_exit - Exits the shell
 * @line: The input line
 * @nread: The number of bytes read
 */

void shell_exit(char *line, ssize_t nread)
{
	if (nread == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(line);
			exit(0);
		}
		free(line);
		perror("Get line error");
		exit(1);
	}

	line[strcspn(line, "\n")] = '\0';
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(0);
	}
}
