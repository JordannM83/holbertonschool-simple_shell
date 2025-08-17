
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
	static int line_count = 1;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		line = read_line();

		if (!line || line[0] == '\0')
		{
			line_count++;
			if (line)
				free(line);
			continue;
		}
		args = parse_line(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "env") == 0)
				print_env();
			else
				execute(args, argv[0], line_count);
		}

		line_count++;
		free(line);
		free(args);
	}
	return (0);
}
