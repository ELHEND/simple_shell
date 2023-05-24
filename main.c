#include "shell.h"
/**
* main - main function 1
*
*Return: 0
*/
int main(void)
{
char *line = NULL;
char **args = NULL;
int status = 0;
do {
printf("#cisfun$ ");
line = read_line();
ar = parse_line(line);
status = execute_command(ar);
free(line);
free(args);
} while (status);
return (0);
}
