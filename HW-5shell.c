#include "shell.h"

/**
 *  * main - Entry point to the simple shell program
 *   *
 *    * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		else if (strcmp(line, "exit\n") == 0)
			exit_shell();
		else
			printf("Command not found: %s", line);
	}

	free(line);
	return (0);
}

/**
 *  * exit_shell - Exits the shell
 *   *
 *    * Return: Nothing
 *     */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}
