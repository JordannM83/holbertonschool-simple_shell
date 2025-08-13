#include "shell.h"

/**
 * Execute a command.
 * This function creates a child process to execute the command.
 */

int execute(char **args)
{
	int i;
	extern char **environ;

	if (args && args[0]) {
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
