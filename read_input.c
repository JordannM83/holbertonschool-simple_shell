#include "shell.h"

/**
 * trim_whitespace - Remove leading and trailing whitespace from a string
 * @str: String to trim
 * Return: Pointer to trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;
	char *start = str;

	/* Trim leading space */
	while (isspace((unsigned char)*start))
		start++;

	if (*start == 0)  /* All spaces? */
	{
		*str = '\0';
		return (str);
	}

	/* Trim trailing space */
	end = start + strlen(start) - 1;
	while (end > start && isspace((unsigned char)*end))
		end--;

	/* Write new null terminator character */
	end[1] = '\0';

	/* Move trimmed string to beginning if needed */
	if (start != str)
		memmove(str, start, strlen(start) + 1);

	return (str);
}

/**
 * read_command - Read command from user input
 * Return: Command string or NULL on EOF
 */

char *read_command(void)
{
	char *line = NULL;
	char *space_pos;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	/* Trim whitespace in place */
	trim_whitespace(line);

	/* Remove arguments - keep only the first word */
	space_pos = strchr(line, ' ');
	if (space_pos)
		*space_pos = '\0';

	return (line);
}
