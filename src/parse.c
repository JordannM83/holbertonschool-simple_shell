#include "shell.h"

/**
 * parse_line - Splits a line into words (tokens).
 * @line: The input line to split.
 * Return: An array of words (strings), NULL-terminated.
 * Must be freed by caller.
 */

char **parse_line(char *line)
{
	size_t i = 0, bufsize = 32;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens || !line)
		return (NULL);

	for (token = strtok(line, " \t\r\n"); token; token = strtok(NULL, " \t\r\n"))
	{
		tokens[i++] = token;
		if (i == bufsize)
		{
			bufsize *= 2;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
