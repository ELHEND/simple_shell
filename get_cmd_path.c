#include "shell.h"

/**
 *  * get_cmd_path - searches for the
 *  given command in the directories in the PATH
 *   * @cmd: the name of the command to search for
 *    *
 *     * Return: a string containing the full path
 *     to the command, or NULL if not found
 */
char *get_cmd_path(char *cmd)
{
	char *path[] = {"/bin", "/usr/bin", NULL};
	int i = 0;
	char *cmd_path = NULL;

	while (path[i] != NULL)
	{
		cmd_path = malloc(strlen(path[i]) + strlen(cmd) + 2);
		if (cmd_path == NULL)
			return (NULL);

		sprintf(cmd_path, "%s/%s", path[i], cmd);

		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);

		free(cmd_path);
		cmd_path = NULL;
		i++;
	}

	return (NULL);
}

