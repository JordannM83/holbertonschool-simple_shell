#include "shell.h"

/**
 * Main function for the shell.
 * This function initializes the shell and enters the main loop.
 */

int main(int argc, char *argv[])
{
	char *nread;

	while(1)
	{
		prompt();
		nread = read_line();
		
		
	}
	return (0);
}
