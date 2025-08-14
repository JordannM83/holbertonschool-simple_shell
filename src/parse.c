#include "shell.h"

/**
 * parse_line - Splits a line into words.
 * @line: The input line to split.
 * Return: An array of words (strings) or NULL on failure.
 */

char **parse_line(char *line)
{
	char *token;
	char **words = NULL;
	int count = 0;
	char *copy;
	int i;

	if (!line)
		return (NULL);

	copy = strdup(line);
	if (!copy)
		return (NULL);

	token = strtok(copy, " \t\n");
	while (token)
	{
		char **tmp = realloc(words, sizeof(char *) * (count + 2));

		if (!tmp)
		{
			free(copy);
			for (i = 0; i < count; i++)
				free(words[i]);
			free(words);
			return (NULL);
		}
		words = tmp;
		words[count] = strdup(token);
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(copy);
	if (words)
		words[count] = NULL;
	return (words);
}
