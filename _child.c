#include "header.h"

/**
 * child - child function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 if code ran successfully.
 */
int child(char *fullpath, char **tokens)
{
	pid_t child_pid;
	int status, ex_status;
	char **envp = environ;

	/* starts a new proccess */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		ex_status = execve(fullpath, tokens, envp);
		if (ex_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
