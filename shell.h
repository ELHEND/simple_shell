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
int execute_command(char **args);
/* HW_2execute.c */
int execute(char **args);
/* HW_exit.c */
void free_args(char **args);
int exit_shell(void);
