#include"shell.h"
/**
 * execute_command - executes input command from the user.
 * @args: An array of pointers to argument strings.
 *
 * Return: 1 (if continue running), 0 (if exit)
 */
int execute_command(char **args)
{
if (args == NULL || args[0] == NULL)
return (1);
if (strcmp(args[0], "exit") == 0)
return (exit_shell());
return (1);
}
/**
 * free_args - frees the memory.
 *
 * @args: The array of argument strings to free
 */
void free_args(char **args)
{
int i;
for (i = 0; args && args[i]; i++)
free(args[i]);
free(args);
}

/**
 * exit_shell - Exits the shell
 *
 * Return: Always returns 0
 */
int exit_shell(void)
{
printf("Exiting shell..\n");
return (0);
}
