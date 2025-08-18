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

	/* Check if there are arguments (spaces followed by non-space characters) */
	space_pos = strchr(line, ' ');
	if (space_pos)
	{
		/* Skip spaces after the command */
		i = space_pos - line + 1;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		/* If there's non-space content after spaces, there are arguments */
		if (line[i] != '\0')
		{
			/* Return the full line with arguments to trigger an error */
			return (line);
		}
		/* If only trailing spaces, remove them */
		*space_pos = '\0';
	}

	return (line);
}
