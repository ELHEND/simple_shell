#include "shell.h"
/**
 * main - The entry point of the program of Simple shell 0.3 +
 *
 * Return: 0
 */
int main(void)
{
char input[1024];
char **args;
int status;
do {
printf("$ ");
fgets(input, sizeof(input), stdin);
args = parse_input(input);
status = execute_command(args);
free_args(args);
} while (status);
return (EXIT_SUCCESS);
}

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
 * parse_input - Parses the user's input into an array of arguments
 * @input: The user's input string
 *
 * Return: An array of argument strings
 */
char **parse_input(char *input)
{
int i = 0;
char **args = malloc(sizeof(char *) * 64);
char *token;
if (args == NULL)
return (NULL);
token = strtok(input, " \t\n");
while (token != NULL)
{
args[i] = strdup(token);
i++;
token = strtok(NULL, " \t\n");
}
args[i] = NULL;
return (args);
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
printf("Exiting shell...\n");
return (0);
}
