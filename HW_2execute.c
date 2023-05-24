#include "shell.h"
/**
 * execute - executes a command.
 * @args: array of arguments.
 *
 * Return: 1 if the shell must continue running, 0 otherwise.
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
if (execvp(args[0], args) == -1)
{
perror("Error");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Error");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
