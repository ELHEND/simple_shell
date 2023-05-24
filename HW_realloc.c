#include "shell.h"
/**
* HW_memset - fills memory with a constant bytes.
* @s: the pointer to the memory area.
* @b: the byte to fill.
* @n: the amount of bytes to be filled.
* Return: s a pointer to the memory area s.
*/
char *HW_memset(char *s, char b, unsigned int n)
{
unsigned int m;
for (m = 0; m < n; m++)
s[m] = b;
return (s);
}
/**
* ffree - frees a string of strings
* @pp: string of strings
*/
void ffree(char **pp)
{
char **k = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(k);
}

/**
* HW_realloc - reallocates a block of memory
* @ptr: pointer to previous malloc'ated block
* @old_size: byte size of previous block
* @new_size: byte size of new block
*
* Return: pointer.
*/
void *HW_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *l;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
l = malloc(new_size);
if (!l)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
l[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (l);
}
