#include "shell.h"
/**
 *  **_strncpy - copies a string
 *   *@dest: the destination string to be copied to
 *    *@src: the source string
 *     *@n: the amount of characters to be copied
 *      *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int m, j;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		j = m;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 *  **_strncat - concatenates two strings
 *   *@dest: the first string
 *    *@src: the second string
 *     *@n: the amount of bytes to be maximally used
 *      *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int m, j;
	char *s = dest;

	m = 0;
	j = 0;
	while (dest[m] != '\0')
		m++;
	while (src[j] != '\0' && j < n)
	{
		dest[m] = src[j];
		m++;
		j++;
	}
	if (j < n)
		dest[m] = '\0';
	return (s);
}

/**
 *  **_strchr - locates a character in a string
 *
 *   *@s: the string to be parsed
 *    *@c: the character to look for
 *     *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
