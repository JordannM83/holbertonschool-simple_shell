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
int execute_command(char *command, char *program_name, int line_count);
void print_error(char *program_name, char *command, int line_count);

/* External variable */
extern char **environ;

#endif /* SIMPLE_SHELL_H */
