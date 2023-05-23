#include "shell.h"

/**
* get_environ - returns the string array copy of the environ
* @info: Structure containing arguments.
*
* Return: Always 0
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_str(info->env);
info->env_changed = 0;
}
return (info->environ);
}
/**
* _unsetenv - Remove the environment variable.
* @info: Structure of arguments.
* @var: the string env var property.
*
* Return: 1 on delete, 0 otherwise.
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t m = 0;
char *P;
if (!node || !var)
return (0);
while (node)
{
P = starts_with(node->str, var);
if (P && *P == '=')
{
info->env_changed = delete_node_index(&(info->env), m);
m = 0;
node = info->env;
continue;
}
node = node->next;
m++;
}
return (info->env_changed);
}

/**
* _setenv - Initializes a new environment variable.
* @info: Structure of args.
* @var: the string env var property
* @value: the string env var value
*
* Return: Always 0
*/
int _setenv(info_t *info, char *var, char *value)
{
char *BUF = NULL;
list_t *node;
char *P;
if (!var || !value)
return (0);
BUF = malloc(_strlen(var) + _strlen(value) + 2);
if (!BUF)
return (1);
_strcpy(BUF, var);
_strcat(BUF, "=");
_strcat(BUF, value);
node = info->env;
while (node)
{
P = starts_with(node->str, var);
if (P && *P == '=')
{
free(node->str);
node->str = BUF;
info->env_changed = 1;
return (0);
}
node = node->next;
}
Add_node_end(&(info->env), BUF, 0);
free(BUF);
info->env_changed = 1;
return (0);
}
