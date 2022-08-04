#include "header.h"

/**
 * errors - prints errors based on case
 * @error: error number associated with statemeant
 * Return: nothing.
 */

void errors(int error)
{
    switch (error)
    {
    case 1: /* writes fork error to stderr */
            write(STDERR_FILENO, FURK_ERR, _strlen(FURK_ERR));
            perror("Error");
            break;
    case 2: /* writes execve error to stderr */
            perror("Error");
            break;
    case 3: /* write malloc error to stderr */
            write(STDERR_FILENO, MALLOC_ERR, _strlen(MALLOC_ERR));
            break;
    case 4: /* write empty path error to stderr */
            write(STDERR_FILENO, PATH_ERR, _strlen(PATH_ERR));
            break;
    
    default:
        return;
    }
}
