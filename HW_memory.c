#include "shell.h"
/**
 * BuFREE- frees a pointer and NULLs the address.
 * @ptr: address of the pointer to be freed.
 *
 * Return: 1 if freed, otherwise 0.
 */
int BuFREE(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
