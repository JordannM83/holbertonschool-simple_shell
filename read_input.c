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
	int i;

	nread = getline(&line, &size, stdin);
	if (nread == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	space_pos = strchr(line, ' ');
	if (space_pos)
	{
		i = space_pos - line + 1;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != '\0')
		{
			return (line);
		}
		*space_pos = '\0';
	}

	return (line);
}
