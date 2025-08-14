
#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		line = read_line();

		if (line == NULL)
			break;
		args = parse_line(line);

		execute(args);
		free(line);
	}
	return (0);
}
