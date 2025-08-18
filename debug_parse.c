#include "shell.h"

/**
 * debug_args - Print arguments for debugging
 * @args: Array of arguments
 */
void debug_args(char **args)
{
	int i = 0;
	
	printf("DEBUG: Arguments parsed:\n");
	while (args && args[i])
	{
		printf("  args[%d] = '%s'\n", i, args[i]);
		i++;
	}
	printf("  args[%d] = NULL\n", i);
}

int main(void)
{
	char *test_line = "/bin/ls -l -a";
	char *test_copy = malloc(strlen(test_line) + 1);
	char **args;
	
	strcpy(test_copy, test_line);
	args = parse_line(test_copy);
	
	debug_args(args);
	
	free(test_copy);
	free(args);
	return (0);
}
