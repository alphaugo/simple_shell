#include "header.h"

/**
 * _getenv - get the value of an environment variable
 * @name: name of the variable
 *
 * Return: pointer to the value of the variable, or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;

	while (environ[environ_length] != NULL)
		environ_length++;

	environ_copy = NULL;
	environ_copy = copy_en(environ_copy, environ_length);

	length = _strlen((char *)name);
	i = 0;
	while (environ_copy[i] != NULL)
	{
		variable = environ_copy[i];
		compare = _strncmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n");
			if (value == '\0')
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
			path_length = _strlen(value);
			path = malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				perror("Error:");
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(environ_copy, environ_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * copy_env - copies environment variable
 * @environ_copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 *
 * Return: double pointer to copy of environment variable
 */
char **copy_en(char **environ_copy, unsigned int environ_length)
{
	char *variable;
	unsigned int variable_length, i;

	environ_copy = malloc(sizeof(char **) * (environ_length));
	if (environ_copy == NULL)
	{
		perror("Error:");
		return (NULL);
	}
	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = _strlen(variable);

		environ_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (environ_copy[i] == NULL)
		{
			perror("Error:");
			return (NULL);
		}
		_strcpy(environ_copy[i], environ[i]);
		i++;
	}
	return (environ_copy);
}
