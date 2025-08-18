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
int execute(char **args, char *prog_name, int line_num);
int execute_command(char *path, char **args, char *prog_name, int line_num);
int find_command(char **args, char *prog_name, int line_num);
void print_error(char *program_name, char *command, int line_count, char *msg);
char **parse_line(char *line);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);
char *my_getenv(const char *name);
char *my_strdup(const char *str);
int trim_line(char *line, int *start);
int process_command(char *line, char *prog_name, int line_count);

/* External variable */
extern char **environ;

#endif /* SIMPLE_SHELL_H */
