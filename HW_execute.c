#include "shell.h"
/**
 * execute_command - Executes a command using the function(execv)
 * @args: Array of arguments for the command.
 *
 * Return: 1 (if success), 0 (if failure).
 */
int execute_command(char **args)
{
pid_t pid;
int status;
if (ar[0] == NULL){
return (1);
}
pid = fork();
if (pid == 0){
/* Child process */
char *program_path = "/usr/bin/ls";
if (execv(program_path, ar) == -1){
perror("Error");
}
exit(EXIT_FAILURE);
}
else if (pid < 0){
/* Error forking */
perror("Error");
}
else{
/* Parent process */
do{
waitpid(pid, &status, WUNTRACED);
}
while(!WIFEXITED(status) && !WIFSIGNALED(status));
=======
if (args[0] == NULL) {
return (1);
}
pid = fork();
if (pid == 0) {
/* Child process */
char *program_path = "/usr/bin/ls";
if (execv(program_path, args) == -1) {
perror("Error");
}
exit(EXIT_FAILURE);
} else if (pid < 0) {
/* Error forking */
perror("Error");
} else {
/* Parent process */
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
>>>>>>> 75983362bfb2f316cfb36fc0a8f784b4b2b414a9
}
return (1);
}
