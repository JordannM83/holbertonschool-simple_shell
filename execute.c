#include "shell.h"

/**
 * execute_command - Execute a command
 * @command: Command to execute
 * @program_name: Name of the shell program
 * @line_count: Current line count
 *
 * Return: Exit status of the command, -1 on error
 */

int execute_command(char *command, char *program_name, int line_count)
{
	pid_t pid;
	int status;
	char **args;
	char *command_copy;

	if (!command)
		return (-1);

	/* Create a copy of command for parsing (strtok modifies the string) */
	command_copy = malloc(strlen(command) + 1);
	if (!command_copy)
		return (-1);
	strcpy(command_copy, command);

	/* Parse the command line into arguments */
	args = parse_line(command_copy);
	if (!args || !args[0])
	{
		free(command_copy);
		if (args)
			free(args);
		return (-1);
	}

	/* Debug: print what we're about to execute */
	/*
	printf("DEBUG: Executing '%s' with args:\n", args[0]);
	for (i = 0; args[i]; i++)
		printf("  [%d]: '%s'\n", i, args[i]);
	*/

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(command_copy);
		free(args);
		return (-1);
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		print_error(program_name, args[0], line_count, "not found");
		free(command_copy);
		free(args);
		exit(127);
	}

	wait(&status);
	free(command_copy);
	free(args);
	return (WEXITSTATUS(status));
}
