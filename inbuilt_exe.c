#include "header.h"

/**
 * inbuilt_exe - executes the built in function
 * @tokens: arguments being passed
 * Return: tokens
 */
int inbuilt_exe(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num, i;

	built builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}};

	if (tokens[0] == NULL)
		return (1);

	length = _strlen(tokens[0]);

	num = shell_num_inbuilts(builtin);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, length) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
**shell_num_builtins - this check num built-ins
**@builtin: takes the builtin to be counted
**Return: num of built-ins
**/
int shell_num_inbuilts(built builtin[])
{
	unsigned int i;
	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (1);
}
