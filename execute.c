#include "shell.h"

/**
 * execute_command - Execute a command
 * @command: Command to execute
 *
 * Return: Exit status of the command, -1 on error
 */

int execute_command(char *command)
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
		perror("execve");
		exit(127);
	}

	wait(&status);
	return (WEXITSTATUS(status));
}
