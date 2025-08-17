#include "shell.h"

/**
 * print_env - Print all environment variables
 */
void print_env(void)
{
	char **env = environ;
	int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
}
