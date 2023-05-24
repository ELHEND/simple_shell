#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* HW_read.c */
char *read_line(void);
char **parse_line(char *line);

/* HW_execute.c */
int execute_command(char **ar);

/* HW_2execute.c */
int execute(char **args);

#endif /* SHELL_H */

