nclude "shell.h"

extern char **environ;

/**
 *  * print_environment - prints the current environment
 *   */
void print_environment(void)
{
	char **env = environ;
	while (*env != NULL) {
		printf("%s\n", *env);
		env++;
	}
}

/**
 *  * main - simple shell program
 *   *
 *    * Return: 0 on success
 *     */
int main(void)
{
	char command[100];

	while (1) {
		printf("$ ");
		fgets(command, sizeof(command), stdin);

		if (strcmp(command, "env\n") == 0) {
			print_environment();
		} else if (strcmp(command, "exit\n") == 0) {
			break;
		}
	}

	return 0;
}

