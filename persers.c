#include "header.h"

/**
 * perser - tokenizes the string
 * @str: user input
 * Return: pointer to array of tokens.
 */
char *perser(char *str)
{
	char *token;
	char *tok;
	unsigned int i;

	token = malloc(sizeof(char) * BUFFER);
	if (token == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	tok = strtok(str, "\n\t\r ");

	i = 0;
	while (tok != NULL)
	{
		token[i] = tok;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}
	token[i] = NULL;
	return (token);
}
