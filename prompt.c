#include "shell.h"

/**
 * handle_signal - Handle SIGINT signal (Ctrl+C)
 * @sig: Signal number
 */
void handle_signal(int sig)
{
	(void)sig;
	printf("\n#cisfun$ ");
	fflush(stdout);
}

/**
 * print_prompt - Print the shell prompt
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
}
