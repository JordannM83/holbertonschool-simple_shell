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
	int i = 0;
	int len;
	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();
		line = read_command();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		i = 0;

		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '\0')
		{
			free(line);
			continue;
		}

		len = strlen(line);
		while (len > i && (line[len - 1] == ' ' || line[len - 1] == '\t'))
		{
			line[len - 1] = '\0';
			len--;
		}
		
		/* Handle built-in commands */
		if (strcmp(line + i, "exit") == 0)
		{
			free(line);
			break;
		}
		
		execute_command(line + i, argv[0], line_count);
		line_count++;
		free(line);
	}
	return (0);
}
