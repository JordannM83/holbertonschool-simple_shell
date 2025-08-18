#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	char *line;
	static int line_count = 1;
	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();
		line = read_command();
		if (!line || line[0] == '\0')
		{
			if (line)
				free(line);
			if (!line)
				break;
			continue;
		}

		execute_command(line);
		line_count++;
		free(line);
	}
	return (0);
}
