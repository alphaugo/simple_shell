#include "header.h"

/**
 * _getline - function that puts input from user to buffer
 *
 * @fd: buffer for user input
 * Return: buffer with input
 */
char *_getline(FILE *fd)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;

	read = getline(&line, &len, fd);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);

}
