#include "header.h"
/**
 * selector - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */

char *selector(char *command, char *fullpath, char *path)
{
    unsigned int commandlength, pathlength, originalpath_length;
    char *pathcopy, *token;

    commandlength = _strlen(command);
    originalpath_length = _strlen(path);
    pathcopy = malloc(sizeof(char) * originalpath_length + 1);

    if (pathcopy == NULL)
    {
        errors (3);
        return (NULL);
    }

    _strcpy(pathcopy, path);

    /* copy PATH directory + command name and check if it exists */
    token = strtok(pathcopy, ":");
    if (token != NULL)
        token = strtok(NULL, ":");
        
    while (token != NULL)
    {
        pathlength = _strlen(token);

        fullpath = malloc(sizeof(char) * (pathlength + commandlength) + 2);

        if (fullpath == NULL)
        {
            errors (3);
            return (NULL);
        }

        _strcpy(fullpath, token);
        fullpath[pathlength] = '/';
        _strcpy(fullpath + pathlength + 1, command);
        fullpath[pathlength + commandlength + 1] = '\0';
        
        if (access(fullpath, X_OK) != 0)
        {
            free(fullpath);
            fullpath = NULL;

            token = strtok(NULL, ":");
        }
        else
            break;
    }
    free (pathcopy);
    return (fullpath);

}
