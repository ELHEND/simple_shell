#include "shell.h"
/**
* main - main function
*
* Return : 0
*/
int main(void)
{
char *line = NULL;
char **ar = NULL;
int status = 0;
do {
printf("#cisfun$ ");
line = read_line();
ar = parse_line(line);
status = execute_command(ar);
free(line);
free(ar);
} while (status);
return (0);
}
