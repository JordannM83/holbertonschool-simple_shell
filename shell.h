#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args, char *prog_name);
void shell_loop(char *prog_name);
void print_prompt(void);
void handle_signal(int sig);

/* Environment variable */
extern char **environ;

#endif /* SHELL_H */
