#include "shell.h"

/**
 * read_line - Read a line of input from stdin
 *
 * Return: The line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(0);
		}
		else
		{
			perror("getline");
			free(line);
			exit(1);
		}
	}

	return (line);
}

/**
 * split_line - Split a line into tokens
 * @line: The line to split
 *
 * Return: Array of tokens
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(1);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(1);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute_command - Execute a command
 * @args: Array of arguments
 * @prog_name: Program name for error messages
 *
 * Return: 1 to continue, 0 to exit
 */
int execute_command(char **args, char *prog_name)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		/* Empty command */
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", prog_name);
		}
		exit(127);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("fork");
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * shell_loop - Main shell loop
 * @prog_name: Program name for error messages
 */
void shell_loop(char *prog_name)
{
	char *line;
	char **args;
	int status;

	/* Set up signal handler for Ctrl+C */
	signal(SIGINT, handle_signal);

	do {
		print_prompt();
		line = read_line();
		args = split_line(line);
		status = execute_command(args, prog_name);

		free(line);
		free(args);
	} while (status);
}
