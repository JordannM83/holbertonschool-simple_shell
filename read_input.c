#include "shell.h"

/**
 * read_command - Read command from user input
 * Return: Command string or NULL on EOF
 */

char *read_command(void)
{
	char *line = NULL;
	char *space_pos;
	size_t size = 0;
	ssize_t nread;

	nread = getline(&line, &size, stdin);
	if (nread == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	/* Remove arguments - keep only first word */
	space_pos = strchr(line, ' ');
	if (space_pos)
		*space_pos = '\0';

	return (line);
}
