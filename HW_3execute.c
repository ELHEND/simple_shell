#include"shell.h"
/**
 *  * execute - Execute a command with its arguments.
 *  * @args: array of arguments.
 *  *
 *  * Return: Always 1 , or 0 to exit
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
