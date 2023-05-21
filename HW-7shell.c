#include "shell.h"

/**
 *  * main - Initialize shell loop
 *   *
 *    * Return: Always 0 on success
 */
int main(void)
{
	char *buffer, **tokens;
	size_t bufsize = BUFSIZE;
	int status;

	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (1)
	{
		printf("$ ");
		getline(&buffer, &bufsize, stdin);

		tokens = parse_input(buffer);
		status = execute(tokens);

		free(tokens);
	}

	free(buffer);
	return (0);
}


/**
 *  * parse_input - Parses user input into command tokens
 *   * @input: User input string
 *    *
 *     * Return: Array of command tokens
 */
char **parse_input(char *input)
{
	const char *DELIMITERS = " \t\n";
	char *token;
	int position = 0;
	char **tokens = malloc(BUFSIZE * sizeof(char *));

	if (!tokens)
	{
		perror("Unable to allocate token buffer");
		exit(1);
	}

	token = strtok(input, DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, DELIMITERS);
	}

	tokens[position] = NULL;
	return (tokens);
}

/**
 *  * execute - Executes a command with arguments
 *   * @args: Command and arguments
 *    *
 *     * Return: Always 1
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("Error executing command");
		}
		exit(1);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("Error forking process");
	}
	else
	{
		/* Parent process */
		do

		{
		waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
