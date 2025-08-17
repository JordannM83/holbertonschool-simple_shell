#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argc;

	/* Run the shell loop with program name */
	shell_loop(argv[0]);

	return (0);
}
