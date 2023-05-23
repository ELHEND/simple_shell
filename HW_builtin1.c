#include "shell.h"

/**
* HW_history - displays the history list, one command by line.
* @info: Structure containing aguments.
*
* Return: Always 0.
*/
int HW_history(info_t *info)
{
print_list(info->history);
return (0);
}
/**
* unset_alias - sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
char *P, C;
int ret;
P = _strchr(str, '=');
if (!P)
return (1);
C = *P;
*P = 0;
ret = delete_node_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*P = C;
return (ret);
}
/**
* set_alias - sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *P;
P = _strchr(str, '=');
if (!P)
return (1);
if (!*++P)
return (unset_alias(info, str));
unset_alias(info, str);
return (Add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints an alias string
* @node: the alias node
*
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *P = NULL, *A = NULL;
if (node)
{
P = _strchr(node->str, '=');
for (A = node->str; A <= P; A++)
_putchar(*A);
_putchar('\'');
_puts(P + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* HW_alias - Mimics the alias builtin .
* @info: Structure containing arguments.
*
* Return: Always 0
*/
int HW_alias(info_t *info)
{
int m = 0;
char *P = NULL;
list_t *node = NULL;
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (m = 1; info->argv[m]; m++)
{
P = _strchr(info->argv[m], '=');
if (P)
set_alias(info, info->argv[m]);
else
print_alias(node_starts_with(info->alias, info->argv[m], '='));
}
return (0);
}
