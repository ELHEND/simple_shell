#include "shell.h"

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

/**
 * *read_line - Reads the input line from stdin
 *
 * Return: pointer to the line.
 */
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
getline(&line, &bufsize, stdin);
return (line);
}

/**
 * *parse_line - Splits a string into multiple tokens.
 * @line: the string to token size.
 *
 * Return: An array of pointers to tokens.
 */
char **parse_line(char *line)
{
char **tokens = NULL;
char *token = NULL;
int pos = 0;
tokens = malloc(sizeof(char *) * 1024);
if (tokens == NULL)
{
fprintf(stderr, "Error: Memory allocation failed. \n");
exit(EXIT_FAILURE);
}
token = strtok(line, " \t\n\r");
while (token != NULL)
{
tokens[pos] = token;
pos++;
token = strtok(NULL, " \t\n\r");
}
tokens[pos] = NULL;
return (tokens);
}

/**
 * execute_command - Executes a command using the function(execvp)
 * @ar: Array of arguments for the command.
 *
 * Return: 1 (if successful), 0 (if failled).
 */
int execute_command(char **ar)
{
pid_t pid;
int status;
if (ar[0] == NULL)
{
return (1);
}
pid = fork();
if (pid == 0)
{
/* child process */
if (execvp(ar[0], ar) == -1)
{
perror("Error");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
perror("Error");
}
else
{
/* Parent process */
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
