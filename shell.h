#ifndef SHELL_H
#define SHELL_H

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

/* HW_beaucode.c */
void print_to_98(int n);

/* HW_shell.c */
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);

#endif
