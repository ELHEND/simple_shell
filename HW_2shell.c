#include "shell.h"

/**
 * main - function for simple shell 0.1
 *
 * Return: 0 in all cases.
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}
/**
 * read_line - reads a line from stdin
 *
 * Return: pointer to the line.
 */
char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * split_line - splits a string into tokens
 * @line: pointer to the string
 *
 * Return: pointer to the array of tokens.
 */
char **split_line(char *line)
{
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		exit(EXIT_FAILURE);

	token = strtok(line, TOKEN_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				exit(EXIT_FAILURE);
		}

		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute - executes a command
 * @args: array of arguments
 *
 * Return: 1 if the shell should continue running, 0 otherwise.
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	pid = fork();
	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("Error");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("Error");
	} else {
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
