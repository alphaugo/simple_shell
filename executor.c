#include "header.h"

/**
 * main - main function.
 *
 * Return: void
 *
 */
int main(void)
{
	char *line, *path, *fullpath;
	char *tokens;
	int flag, builtin_stat, child_stat;
	struct stat buf;

	while (TRUE)
	{
		prompt(STDIN_FILENO, buf);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = perser(line);
		if (tokens[0] == NULL)
			continue;
		builtin_stat = inbuilt_exe(tokens);
		if (builtin_stat = inbuilt_exe(tokens))
		{
			free(tokens);
			free(line);
		}
		if (builtin_stat == 0)
			continue;
		if (builtin_stat == -1)
			exit(EXIT_SUCCESS);

		flag = 0; /* i.e if fullpath is not malloced */
		path = _getenv("PATH");
		fullpath = selector(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1; /* if fullpath was malloced, flag to free */

		child_stat = child(fullpath, tokens);
		if (child_stat == -1)
			perror("Error:");
		freeall(tokens, path, line, fullpath, flag);
	}
	return (0);
}
