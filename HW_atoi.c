#include "shell.h"

/**
 * interactive - returns true if the shell is in an interactive mode.
 * @info: struct address.
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * HW_delim - checks if character is a delimeter or not .
 * @j: the char to check.
 * @delim: the delimeter string.
 * Return: 1 if true, 0 if false.
 */
int HW_delim(char j, char *delim)
{
while (*delim)
if (*delim++ == j)
return (1);
return (0);
}

/**
 * HW_isalpha - checks for alphabetic character.
 * @j: The character to input.
 * Return: 1 if j is alphabetic, 0 otherwise.
 */

int HW_isalpha(int j)
{
if ((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z'))
return (1);
else
return (0);
}

/**
 * HW_atoi - converts a string to an integer.
 * @s: the string to be converted.
 * Return: 0 if no numbers in string, returns converted number otherwise.
 */
int HW_atoi(char *s)
{
int m, sign = 1, flag = 0, output;
unsigned int result = 0;
for (m = 0; s[m] != '\0' && flag != 2; m++)
{
if (s[m] == '-')
sign *= -1;
if (s[m] >= '0' && s[m] <= '9')
{
flag = 1;
result *= 10;
result += (s[m] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
