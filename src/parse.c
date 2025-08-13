#include "shell.h"

/**
 * Parse a command line input.
 * This function splits the input line into individual arguments.
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
			return NULL;
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
