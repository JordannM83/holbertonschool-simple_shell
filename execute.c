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
	char *paths[] = {"/bin/", "/usr/bin/", NULL};
	char full_path[1024];
	int i;

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
		/* If command contains '/', try to execute it as is */
		if (strchr(command, '/'))
		{
			execve(command, args, environ);
		}
		else
		{
			/* Try to find command in standard paths */
			for (i = 0; paths[i]; i++)
			{
				snprintf(full_path, sizeof(full_path), "%s%s", paths[i], command);
				execve(full_path, args, environ);
			}
		}
		print_error(program_name, command, line_count, "not found");
		exit(127);
	}

	wait(&status);
	return (WEXITSTATUS(status));
}
