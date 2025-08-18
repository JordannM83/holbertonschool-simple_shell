#include "shell.h"

/**
 * test_execve - Test execve directly with parsed arguments
 */
int main(void)
{
	char *test_line = "/bin/ls -l";
	char *test_copy = malloc(strlen(test_line) + 1);
	char **args;
	pid_t pid;
	int status;
	int i;
	
	strcpy(test_copy, test_line);
	args = parse_line(test_copy);
	
	printf("About to execute: %s with args:\n", args[0]);
	for (i = 0; args[i]; i++)
		printf("  [%d]: '%s'\n", i, args[i]);
	
	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		printf("execve failed\n");
		exit(127);
	}
	else if (pid > 0)
	{
		wait(&status);
		printf("Command finished with status: %d\n", WEXITSTATUS(status));
	}
	
	free(test_copy);
	free(args);
	return (0);
}
