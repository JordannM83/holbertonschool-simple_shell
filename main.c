
#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *line;
	char **args;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		line = read_line();

		if (line == NULL)
			break;
		args = parse_line(line);

		execute(args, argv[0]);
		free(line);
	}
	return (0);
}
