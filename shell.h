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

#endif
