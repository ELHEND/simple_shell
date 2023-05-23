#include "shell.h"

/**
 *  **_strncpy - copies a string.
 *  *@dest: the destination string to be copied to.
 *  *@src: the source of the string to copy.
 *  *@o: the number of characters to be copied.
 *  *
 *   *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int o)
{
	int m, n;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < o - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < o)
	{
		n = m;
		while (n < o)
		{
			dest[n] = '\0';
			n++;
		}
	}
	return (s);
}

/**
 *  **_strncat - concatenates two strings.
 *  *@dest: the first string.
 *  *@src: the second string.
 *  *@o: the amount of bytes to be used.
 *  *
 *   *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int o)
{
	int m, n;
	char *s = dest;

	m = 0;
	n = 0;
	while (dest[m] != '\0')
		m++;
	while (src[n] != '\0' && n < o)
	{
		dest[m] = src[n];
		m++;
		n++;
	}
	if (n < o)
		dest[m] = '\0';
	return (s);
}

/**
 *  **_strchr - locates a character in a string.
 *  *@s: the string to be parsed.
 *  *@c: the character to search for.
 *  *Return: s a pointer to the memory area s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
