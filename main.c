#include "shell.h"

/**
 * main - Entry point of the program
 * Return: always 0 on success
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

return (EXIT_SUCCESS);
}

