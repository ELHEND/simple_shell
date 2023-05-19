/**
 * main - entry point for the shell
 *
 * Return: always 0 on success, -1 on failure.
 */
int main(void)
{
char *input, **tokens;
int status;
while (1)
{
printf("$ ");
input = get_input();
tokens = tokenize(input);
status = built_in(tokens) == 0 ? 0 : 1;
if (status == 0 && tokens[0] != NULL)
execute(tokens);
free(input);
free(tokens);
}
return (0);
}
/**
 * get_input - gets input from user
 *
 * Return: input on success, NULL on failure.
 */
char *get_input(void)
{
static char buffer[MAX_INPUT];
int c;
unsigned int i = 0;
while ((c = getchar()) != '\n' && c != EOF)
{
buffer[i] = c;
i++;
if (i >= MAX_INPUT)
{
fprintf(stderr, "error: input too long\n");
exit(EXIT_FAILURE);
}
}
if (c == EOF)
exit(EXIT_SUCCESS);
buffer[i] = '\0';
return (strdup(buffer));
}
/**
 * tokenize - tokenizes a string
 * @input: string to be tokenized
 *
 * Return: array of tokens on success, NULL on failure.
 */
char **tokenize(char *input)
{
char *token;
char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
int i = 0;
if (!tokens)
return (NULL);
token = strtok(input, " \t\r\n\a");
while (token != NULL)
{
tokens[i] = token;
i++;
token = strtok(NULL, " \t\r\n\a");
}
tokens[i] = NULL;
return (tokens);
}
/**
 * built_in - checks if command is a shell builtin
 * @tokens: array of tokens
 *
 * Return: 0 if command exists and is executed, else return 1.
 */
int built_in(char **tokens)
{
/* list of builtin commands */
char *builtins[] = {"exit", NULL};
/* check if command is a builtin command */
for (int i = 0; builtins[i]; i++)
{
if (strcmp(tokens[0], builtins[i]) == 0)
{
if (i == 0)
exit(EXIT_SUCCESS);
return (0);
}
}
return (1);
}
/**
 * execute - executes a command
 * @tokens: array of tokens
 *
 * Return: always 0 on success, -1 on failure.
 */
void execute(char **tokens)
{
pid_t pid;
int status;
pid = fork();
if (pid < 0)
{
fprintf(stderr, "error: failed to fork process\n");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
/* child process */
if (execvp(tokens[0], tokens) == -1)
{
fprintf(stderr, "error: command not found\n");
exit(EXIT_FAILURE);
}
}
else
{ /* parent process */
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status)  && !WIFSIGNALED(status));
}
}
