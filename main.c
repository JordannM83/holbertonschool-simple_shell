#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argc;

		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		args = parse_line(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "env") == 0)
				print_env();
			else
				execute(args, argv[0]);
		}
		free(line);
		free(args);
	}
	return (0);
}
