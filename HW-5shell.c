#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char *token;
	const char delimiter[2] = " ";
	char *args[100];
	int i = 0;

	while (1)
	{
		printf("$ ");
		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		token = strtok(buffer, delimiter);
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, delimiter);
		}
		args[i-1][strlen(args[i-1]) - 1] = '\0';

		if (strcmp(args[0], "env") == 0)
		{
			print_env();
		}
		else if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				execvp(args[0], args);
				perror("execvp");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
			}
		}

		i = 0;
	}

	return 0;
}

/**
 *  * print_env - print current environment variables
 *   */
void print_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
