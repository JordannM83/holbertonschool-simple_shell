#include "shell.h"

/**
 * execute_command - Execute a command with given path
 * @path: Full path to the command
 * @args: Array of arguments
 *
 * Return: Exit status of the command
 */
int execute_command(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		print_error("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(path, args, environ);
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		exit(127);
	}

	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

/**
 * find_command - Find command in PATH
 * @args: Array of arguments
 *
 * Return: 0 on success, 127 on failure
 */
int find_command(char **args)
{
	char *path, *path_copy, *token, *full_path;
	int result;

	path = getenv("PATH");
	if (!path)
		return (127);

	path_copy = strdup(path);
	if (!path_copy)
		return (127);

	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(args[0]) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (127);
		}

		sprintf(full_path, "%s/%s", token, args[0]);
		if (access(full_path, F_OK) == 0)
		{
			result = execute_command(full_path, args);
			free(full_path);
			free(path_copy);
			return (result);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (127);
}

/**
 * execute - Execute a command in a child process
 * @args: Array of arguments for the command
 *
 * Return: Exit status of the command
 */
int execute(char **args)
{
	int result;

	if (!args || !args[0])
		return (-1);

	/* Check if command is an absolute path */
	if (access(args[0], F_OK) == 0)
		return (execute_command(args[0], args));

	/* Search in PATH */
	result = find_command(args);
	if (result == 127)
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);

	return (result);
}
