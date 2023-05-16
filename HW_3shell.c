#include "shell.h"
/**
 * main - Entry point of the shell
 *
 * Return: Always 0
 */
int main(void)
{
char *line = NULL;
char **args = NULL;
size_t len = 0;
while (1)
{
printf("$ ");
if (getline(&line, &len, stdin) == -1)
break;
args = split_line(line);
execute(args);
free(line);
free(args);
line = NULL;
args = NULL;
}
return (0);
}
/**
 * split_line - Split a string into an array of strings
 * @line: The input string to be splitted
 *
 * Return: An array of strings with the splitted line
 */
char **split_line(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
if (!tokens)
{
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
fprintf(stderr, "Memory allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return (tokens);
}
/**
 * execute - Execute a command with its arguments
 * @args: An array of strings representing the command and its arguments
 *
 * Return: Always 1 to continue execution, or 0 to exit
 */
int execute(char **args)
{
pid_t pid;
int status;
if (args[0] == NULL)
return (1);
pid = fork();
if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
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
