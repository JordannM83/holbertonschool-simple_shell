#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* includes here */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

/* function prototypes here */
void prompt(void);
char *read_command(void);
char *trim_whitespace(char *str);
int execute_command(char *command);
void print_error(char *program_name, char *command);

/* External variable */
extern char **environ;

#endif /* SIMPLE_SHELL_H */
