#include "shell.h"

/**
 * Main function for the shell.
 * This function initializes the shell and enters the main loop.
 */

int main(int argc, char *argv[])
{
	char *line;
	char **args;

	while(1)
	{
		prompt();
		line = read_line();
		if (line == NULL)
			break;
		**args = **parse_line(line);
	}
	free (line);
	return (0);
}
