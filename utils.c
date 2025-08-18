#include "shell.h"

/**
 * my_getenv - Get environment variable value
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, NULL if not found
 */
char *my_getenv(const char *name)
{
	int i = 0;
	int name_len;
	char *env_var;

	if (!name || !environ)
		return (NULL);

	name_len = strlen(name);

	while (environ[i])
	{
		env_var = environ[i];
		if (strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
			return (env_var + name_len + 1);
		i++;
	}

	return (NULL);
}

/**
 * my_strdup - Duplicate a string
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, NULL on failure
 */
char *my_strdup(const char *str)
{
	char *dup;
	int i = 0, len;

	if (!str)
		return (NULL);

	len = strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}
