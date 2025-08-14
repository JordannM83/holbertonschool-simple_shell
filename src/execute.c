#include "shell.h"
#include <stdio.h>
/**
 * Execute a command.
 * This function creates a child process to execute the command
 * using execve. It handles errors by printing them to stderr.
 * @args: An array of arguments for the command, including the command itself.
 * Returns 0 on success, or -1 on failure.
 * Note: The caller is responsible for freeing the args array.
 * execute - Executes a command in a child process.
 * @args: The arguments for the command.
 * Return: 0 on success, -1 on failure.
 */

int execute(char **args)
{
	int i;

	if (args && args[0])
	{
			pid_t pid = fork();
	if (args && args[0])
	{
		pid_t pid = fork();

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
			}
			for (i = 0; args[i]; i++)
				free(args[i]);
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
		}
		for (i = 0; args[i]; i++)
			free(args[i]);

			free(args);
	}
		free(args);
	}
	return (0);
}
