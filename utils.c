#include "shell.h"

/**
 * my_strdup - Duplicates a string
 * @s: String to duplicate
 * Return: Pointer to duplicated string or NULL on failure
 */
char *my_strdup(const char *s)
{
	char *dup;
	int len, i;

	if (!s)
		return (NULL);

	len = 0;
	while (s[len])
		len++;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = s[i];

	return (dup);
}

/**
 * my_getenv - Gets environment variable value
 * @name: Name of the environment variable
 * Return: Value of the variable or NULL if not found
 */
char *my_getenv(const char *name)
{
	int i, j;
	int name_len = 0;

	if (!name || !environ)
		return (NULL);

	while (name[name_len])
		name_len++;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < name_len && environ[i][j] == name[j]; j++)
			;
		if (j == name_len && environ[i][j] == '=')
			return (&environ[i][j + 1]);
	}
	return (NULL);
}

/**
 * my_realloc - Reallocates memory block
 * @ptr: Pointer to previously allocated memory
 * @old_size: Size of old memory block
 * @new_size: Size of new memory block
 * Return: Pointer to reallocated memory or NULL on failure
 */
void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;
	char *old_char_ptr, *new_char_ptr;
	size_t i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_char_ptr = (char *)ptr;
	new_char_ptr = (char *)new_ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		new_char_ptr[i] = old_char_ptr[i];

	free(ptr);
	return (new_ptr);
}

/**
 * read_line - Reads a line of input from the user.
 * Return: A pointer to the input string or NULL on failure.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	shell_exit(line, nread);
	return (line);
}
