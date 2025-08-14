#include "shell.h"
#include <stdio.h>
/**
 * Execute a command.
 * This function creates a child process to execute the command
 * using execve. It handles errors by printing them to stderr.
 * @args: An array of arguments for the command, including the command itself.
 * Returns 0 on success, or -1 on failure.
 * Note: The caller is responsible for freeing the args array.
 */

int execute(char **args)
{
	int i;
	extern char **environ;

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

			free(args);
	}
	return (0);
}
