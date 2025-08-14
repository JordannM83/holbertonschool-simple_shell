#include "shell.h"

/**
 * execute - Execute a command in a child process
 * @args: Array of arguments for the command
 *
 * Description: Creates a child process to execute the command using execve.
 * Handles errors by printing them to stderr.
 * Return: 0 on success, -1 on failure
 */
int execute(char **args)
{
	pid_t pid;

	if (args && args[0])
	{
		pid = fork();

		if (pid == 0)
		{
			execve(args[0], args, environ);
			print_error("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			print_error("fork");
			return (-1);
		}
		free(args);
	}
	return (0);
}
