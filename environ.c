#include "shell.h"
/**
* HW_env - prints the current environment.
* @info: Structure containing arguments.
*
* Return: Always 0
*/
int HW_env(info_t *info)
{
Print_list_str(info->env);
return (0);
}
/**
* _getenv - gets the value of an environ variable.
* @info: Structure containing arguments
* @name: env var name.
*
* Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *NODE = info->env;
char *P;
while (NODE)
{
P = starts_with(NODE->str, name);
if (P && *P)
return (P);
NODE = NODE->next;
}
return (NULL);
}
/**
* HW_setenv - Initializes a new environment variable.
* @info: Structure containing arguments.
*
* Return: Always 0
*/
int HW_setenv(info_t *info)
{
if (info->argc != 3)
{
HW_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}
/**
* HW_unsetenv - Remove an environment variable
* @info: Structure containing arguments.
*
* Return: Always 0
*/
int HW_unsetenv(info_t *info)
{
int m;
if (info->argc == 1)
{
HW_eputs("Too few arguements.\n");
return (1);
}
for (m = 1; m <= info->argc; m++)
_unsetenv(info, info->argv[m]);
return (0);
}
/**
* populate_env_list - populates env linked list.
* @info: Structure containing arguments.
*
* Return: Always 0
*/
int populate_env_list(info_t *info)
{
list_t *NODE = NULL;
size_t m;
for (m = 0; environ[m]; m++)
Add_node_end(&NODE, environ[m], 0);
info->env = NODE;
return (0);
}
