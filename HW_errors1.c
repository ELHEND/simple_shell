#include "shell.h"


/**
 * * HW_erratoi - convert a string to an integer.
 * * @s: the string to be converted.
 * *
 * * Return: 0 if no numbers in string, converted numbers otherwise.
 * * (-1) if error.
 */
int HW_erratoi(char *s)
{
	int m = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (m = 0; s[m] != '\0'; m++)
	{
		if (s[m] >= '0' && s[m] <= '9')
		{
			result *= 10;
			result += (s[m] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * * print_error - prints error message.
 * * @info: the parameter struct.
 * * @estr: string containing specified error type.
 * *
 * * Return: 0 if no numbers in string, converted number otherwise
 * * (-1) if error
 */
void print_error(info_t *info, char *estr)
{
	HW_eputs(info->fname);
	HW_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	HW_eputs(": ");
	HW_eputs(info->argv[0]);
	HW_eputs(": ");
	HW_eputs(estr);
}
/**
 * * print_d - prints a decimal (integer).
 * * @input: input.
 * * @yb: the filedescriptor to write.
 * *
 * * Return: number of characters printed.
 */
int print_d(int input, int yb)
{
	int (*__putchar)(char) = _putchar;
	int m, count = 0;
	unsigned int abs, current;

	if (yb == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		abs = -input;
		__putchar('-');
		count++;
	}
	else
		abs = input;
	current = abs;
	for (m = 1000000000; m > 1; m /= 10)
	{
		if (abs / m)
		{
			__putchar('0' + current / m);
			count++;
		}
		current %= m;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * * convert_number - converter function.
 * * @num: number.
 * * @base: base.
 * * @flags: flags.
 * *
 * * Return: string.
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long o = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		o = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (o != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * * remove_comments - replaces first instance of '#' with '\0'
 * * @BUF: address of the string to modify
 * *
 * * Return: Always 0;
 */
void remove_comments(char *BUF)
{
	int m;

	for (m = 0; BUF[m] != '\0'; m++)

		if (BUF[m] == '#' && (!m || BUF[m - 1] == ' '))
		{
			BUF[m] = '\0';
			break;
		}
}
