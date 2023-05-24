#include"shell.h"
/**
 * free_args - frees the memory.
 *
 * @ar: The array of argument strings to free
 */
void free_args(char **ar)
{
int i;
for (i = 0; ar && ar[i]; i++)
free(ar[i]);
free(ar);
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
