#include "shell.h"

/**
 * execute - Execute a command (simple version for task 0.1)
 * @args: Array of arguments for the command
 * @prog_name: Name of the program (argv[0])
 *
 * Return: Exit status of the command
 */
int execute(char **args, char *prog_name)
{
	pid_t pid;
	int status;

	if (!args || !args[0])
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
		exit(127);
	}

	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
