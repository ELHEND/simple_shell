#include "shell.h"
/**
* history_file - gets the history file.
* @info: struct parameter.
*
* Return: string containg history file.
*/
char *history_file(info_t *info)
{
char *BUF, *DIR;
DIR = _getenv(info, "HOME=");
if (!DIR)
return (NULL);
BUF = malloc(sizeof(char) * (_strlen(DIR) + _strlen(HIST_FILE) + 2));
if (!BUF)
return (NULL);
BUF[0] = 0;
_strcpy(BUF, DIR);
_strcat(BUF, "/");
_strcat(BUF, HIST_FILE);
return (BUF);
}
/**
* writes_history - creates  file.
* @info: the parameter struct.
*
* Return: 1 if success, else -1
*/
int writes_history(info_t *info)
{
ssize_t yb;
char *filename = history_file(info);
list_t *node = NULL;
if (!filename)
return (-1);
yb = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (yb == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, yb);
_putfd('\n', yb);
}
_putfd(BUF_FLUSH, yb);
close(yb);
return (1);
}
/**
* read_history - reads history from the file.
* @info: struct parameter.
*
* Return: histcount if success, 0 otherwise
*/
int read_history(info_t *info)
{
int m, last = 0, linecount = 0;
ssize_t yb, rdlen, fsize = 0;
struct stat st;
char *BUF = NULL, *filename = history_file(info);
if (!filename)
return (0);
yb = open(filename, O_RDONLY);
free(filename);
if (yb == -1)
return (0);
if (!fstat(yb, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
BUF = malloc(sizeof(char) * (fsize + 1));
if (!BUF)
return (0);
rdlen = read(yb, BUF, fsize);
BUF[fsize] = 0;
if (rdlen <= 0)
return (free(BUF), 0);
close(yb);
for (m = 0; m < fsize; m++)
if (BUF[m] == '\n')
{
BUF[m] = 0;
build_history_list(info, BUF + last, linecount++);
last = m + 1;
}
if (last != m)
build_history_list(info, BUF + last, linecount++);
free(BUF);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}
/**
* build_history_list - adds entry to a history linked list
* @info: Structure containing potential arguments. Used to maintain
* @buf: buffer
* @linecount: the history linecount, histcount
*
* Return: Always 0
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;
if (info->history)
node = info->history;
Add_node_end(&node, buf, linecount);
if (!info->history)
info->history = node;
return (0);
}
/**
* renumber_history - renumbers the history linked list after changes
* @info: Structure containing potential arguments. Used to maintain
*
* Return: the new histcount
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int m = 0;
while (node)
{
node->num = m++;
node = node->next;
}
return (info->histcount = m);
}
