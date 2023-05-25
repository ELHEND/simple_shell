
#include "shell.h"

/**
 *  * execute _com- executes the given command with its arguments
 *   * @cmd_path: the full path to the command to execute
 *    * @args: an array of strings containing the arguments for the command
 *     *
 *      * Return: 1 on success, 0 on failure
 */
int execute_com(char *cmd_path, char **args)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1) /* fork error */
	{
		perror("fork");
		exit(1);
	}
	else if (child_pid == 0) /* child process */
	{
		if (execv(cmd_path, args) == -1) /* execute command with arguments */
		{
			perror("execv");
			free(cmd_path);
			exit(1);
		}
	}
	else /* parent process */
	{
		waitpid(child_pid, &status, 0); /* wait for child process to finish */
	}

	free(cmd_path);

	return (1);
}

