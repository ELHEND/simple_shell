#ifndef SHELL_H
#define SHELL_H
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_TOKENS 100
#define BUFSIZE 1024
/* main.c */
int main(void);
/* HW_beaucode.c */
void print_to_98(int n);

/* HW_shell.c */
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **ar);

/* HW_2shell.c */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
/*  HW_3shell.c */
int execute(char **args);
char **split_line(char *line);
/* HW-4shell.c */
int execute_command(char **args);
char **parse_input(char *input);
void free_args(char **args);
int exit_shell(void);

/* HW-5shell.c */
int execute(char **args);
int execute_builtin(char **args);
/* HW_6shell.c */
char *custom_getline(void);
char **tokenize(char *input);
int built_in(char **tokens);
int execute(char **args);
/* HE-7shell.c */
char **parse_input(char *input);
int execute(char **args);
#endif
