#include "shell.h"
/**
 * print_to_98 - prints all natural numbers from n to 98,
 * followed by a new line
 * @n: number to start with.
 *
 * Return: nothing
 */
void print_to_98(int n)
{
while (n != 98)
{
printf("%d, ", n);
if (n > 98)
n--;
else
n++;
}
printf("%d\n", n);
}
