#include "shell.h"
/**
* read_line - Reads the input line from stdin
*
* Return: Pointer to the line.
*/
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
getline(&line, &bufsize, stdin);
return (line);
}

/**
* parse_line - Splits a string into multiple tokens.
* @line: The string to token size.
*
* Return: An array of pointers to tokens.
*/
char **parse_line(char *line)
{
char **tokens = NULL;
char *token = NULL;
int pos = 0;
tokens = malloc(sizeof(char *) * 1024);
if (tokens == NULL) {
fprintf(stderr, "Error: Memory allocation failed. \n");
exit(EXIT_FAILURE);
}
token = strtok(line, " \t\n\r");
while (token != NULL) {
tokens[pos] = token;
pos++;
token = strtok(NULL, " \t\n\r");
}
tokens[pos] = NULL;
return (tokens);
}
