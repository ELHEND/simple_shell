#include "shell.h"

/**
 * * HW_eputs - prints an input string
 * * @str: the string to be printed
 * *
 * * Return: Nothing
 * */
void HW_eputs(char *str)
{
	int m = 0;
	if (!str)
		return;
	while (str[m] != '\0')
	{
		_eputchar(str[m]);
		m++;
	}
}
/**
 * * _eputchar - writes the character c to stderr
 * * @c: The character to print
 * *
 * * Return: On success 1.
 * * if error, -1 is returned.
 * */
int _eputchar(char c)
{
	static int m;
	static char BUF[WRITE_BUF_SIZE];
	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(2, BUF, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}

/**
 * * _putfd - writes the character c to given fd
 * * @c: The character to print
 * * @yb: The filedescriptor to write to
 * *
 * * Return: On success 1.
 * * if error, -1 is returned.
 * */
int _putfd(char c, int yb)
{
	static int m;
	static char BUF[WRITE_BUF_SIZE];
	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(yb, BUF, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}
/**
 * * _putsfd - prints an input string
 * * @str: the string to be printed
 * * @yb: the filedescriptor to write to
 * *
 * * Return: the number of chars put
 * */
int _putsfd(char *str, int yb)
{
	int m = 0;
	if (!str)
		return (0);
	while (*str)
	{
		m += _putfd(*str++, yb);
	}
	return (m);
}
