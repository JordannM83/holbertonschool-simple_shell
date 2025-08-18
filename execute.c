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
	char *args[2];

	if (!command)
		return (-1);

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(command, args, environ);
		print_error(program_name, command, line_count, "not found");
		exit(127);
	}

	wait(&status);
	return (WEXITSTATUS(status));
}
