#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
void prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute(char **args);
void print_env(void);
void shell_exit(void);
void print_error(const char *msg);

extern char **environ;

#endif /* SHELL_H */
