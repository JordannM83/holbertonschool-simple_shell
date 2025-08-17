#include "shell.h"

/**
 * prompt - Print the shell prompt
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
}
