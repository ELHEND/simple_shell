#include "shell.h"
/**
* **strtow - splits a string into multiple words.
* @str: the input string to be splited.
* @d: the delimeter string.
* Return: a pointer to an array of strings, or NULL if fail.
*/
char **strtow(char *str, char *d)
{
int m, n, e, f, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (m = 0; str[m] != '\0'; m++)
if (!HW_delim(str[m], d) && (HW_delim(str[m + 1], d) || !str[m + 1]))
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (m = 0, n = 0; n < numwords; n++)
{
while (HW_delim(str[m], d))
m++;
e = 0;
while (!HW_delim(str[m + e], d) && str[m + e])
e++;
s[n] = malloc((e + 1) * sizeof(char));
if (!s[n])
{
for (e = 0; e < n; e++)
free(s[e]);
free(s);
return (NULL);
}
for (f = 0; f < e; f++)
s[n][f] = str[m++];
s[n][f] = 0;
}
s[n] = NULL;
return (s);
}

/**
* **strtow2 - splits a string into words
* @str: the input string
* @d: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char d)
{
int m, n, e, f, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
for (m = 0; str[m] != '\0'; m++)
if ((str[m] != d && str[m + 1] == d) ||
(str[m] != d && !str[m + 1]) || str[m + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (m = 0, n = 0; n < numwords; n++)
{
while (str[m] == d && str[m] != d)
m++;
e = 0;
while (str[m + e] != d && str[m + e] && str[m + e] != d)
e++;
s[n] = malloc((e + 1) * sizeof(char));
if (!s[n])
{
for (e = 0; e < n; e++)
free(s[e]);
free(s);
return (NULL);
}
for (f = 0; f < e; f++)
s[n][f] = str[m++];
s[n][f] = 0;
}
s[n] = NULL;
return (s);
}
