#include "header.h"

/**
 * @brief
 * prompt - function.
 *
 * @param fd
 * @param buf
 */
void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - function
 *
 * @str: parameter
 *
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}
