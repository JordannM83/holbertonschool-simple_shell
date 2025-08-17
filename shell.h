#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Constants */
#define MAX_ARGUMENTS 64
#define MAX_PATH_LENGTH 1024

/* Function prototypes */
void prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args, char *prog_name);
int execute_command(char *path, char **args, char *prog_name);
int find_command(char **args, char *prog_name);
void print_env(void);
void shell_exit(char *line, ssize_t nread);
char *my_strdup(const char *s);
char *my_getenv(const char *name);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);

extern char **environ;

#endif /* SHELL_H */
