#include "shell.h"

/**
 * trim_line - Remove leading and trailing spaces from a line
 * @line: The line to trim
 * @start: Pointer to store the start index
 * Return: Length after trimming
 */
int trim_line(char *line, int *start)
{
	int len;

	*start = 0;
	while (line[*start] == ' ' || line[*start] == '\t')
		(*start)++;

	if (line[*start] == '\0')
		return (0);

	len = strlen(line);
	while (len > *start && (line[len - 1] == ' ' || line[len - 1] == '\t'))
	{
		line[len - 1] = '\0';
		len--;
	}

	return (len);
}

/**
 * process_command - Process a single command line
 * @line: The command line to process
 * @prog_name: Program name for error messages
 * @line_count: Current line number
 * Return: Exit status of the command
 */
int process_command(char *line, char *prog_name, int line_count)
{
	char **args;
	int start, exit_status = 0;

	if (!trim_line(line, &start))
		return (0);

	args = parse_line(line + start);
	if (args && args[0])
	{
		exit_status = execute(args, prog_name, line_count);
		free(args);
	}

	return (exit_status);
}

/**
 * main - Entry point for the shell program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * Return: Exit status of the last command
 */
int main(int argc, char **argv)
{
	char *line;
	static int line_count = 1;
	int exit_status = 0;
	(void)argc;

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
		line[strcspn(line, "\n")] = '\0';
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		exit_status = process_command(line, argv[0], line_count);
		line_count++;
		free(line);
	}

	return (exit_status);
}
