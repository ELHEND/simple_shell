#include "shell.h"
/**
 *  * _strcpy - Duplicates a sequence of characters.
 *   * @dest: the destination
 *    * @src: the origin
 *     * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int m = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[m])
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = 0;
	return (dest);
}

/**
 *  * _strdup - Copies a sequence of characters identically.
 *   * @str: the string to duplicate
 *    * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *  *_puts - Outputs the provided string to a display device.
 *   *@str: the string to be printed
 *    * Return: Nothing
 */
void _puts(char *str)
{
	int m = 0;

	if (!str)
		return;
	while (str[m] != '\0')
	{
		_putchar(str[m]);
		m++;
	}
}

/**
 *  * _putchar - Outputs the character 'c' to the standard output stream.
 *   * @c: The character to print
 *    * Return: On success 1.
 *      * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}
