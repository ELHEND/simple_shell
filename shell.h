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
#include <stdio.h>
#include <stdlib.h>
/* HW_read.c */
char *read_line(void);
char **parse_line(char *line);

/* HW_execute.c */
int execute_command(char **ar);

/* HW_2execute.c */
int execute(char **args);
/* shell.c */
char **parse_command(char *);
int execute_command(char **);
int cd_builtin(char **);
int env_builtin(char **);
int execute_builtin_command(char **, char **);
/*  HW-execut.c */
extern char *path[];

char *get_cmd_path(char *cmd);
void prompt(void);
#endif /* SHELL_H */

