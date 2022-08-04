#ifndef _MAIN_HEAD_
#define _MAIN_HEAD_

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
#define MALLOC_ERR "Unable to allocate memory dynamically"
#define FORK_ERR "Unable to fork"
#define PATH_ERR "No such file nor directory"

extern char **environ;

/**
 * struct list - linked list
 * 
 * @value: value and head
 * 
 * @next: pointer to the next node
 * Description: generic linkedlist
 */
typedef struct list
{
    char *value;
    struct list *next;
}list;

/**
 * struct built - structure
 * 
 * @name: name
 * @p: pointer to a function
 * 
 * Description: structure for builtin functions
 */
typedef struct built
{
    char *name;
    int (*p)(void);
}built;

void prompt(int fd, struct stat buf);
char *_getline(FILE *fd);
char *_getenv(const char *name);
char *perser(char *str);
int inbuilt_exe(char **tokens);
char *selector(char *command, char *fullpath, char *path);
/* free functions */
void freeall(char **tokens, char *path, char *line, char *fullpath, int flag);
void free_dp(char **array, unsigned int length);

/* Utility functions */
void _puts(char *str);
int _strlen(const char *str);
int _strcmp(char *name, char *variable, unsigned int length);
int _strncmp(char *name, char *variable, unsigned int length);
char *_strcpy(char *dest, char *src);

/* prototype for inbuilt functions */
int shell_env(void);
int shell_exit(void);
int inbuilt_exe(char **tokens);
int shell_num_inbuilts(built builtin[]);
#endif
