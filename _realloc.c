#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @str: pointer to the memory space
 * @byt: byte to fill str with
 * @n: number of bytes to be filled
 * Return: the pointer str
 */
char *_memset(char *str, char byt, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = byt;
	return (str);
}

/**
 * _free - frees an array of strings
 * @ptr: address of the array
 * Return: nothing
 */
void _free(char **ptr)
{
	char **h = ptr;

	if (!ptr)
		return;
	while (*ptr)
		free(*ptr++);
	free(h);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previous malloc'ed block
 * @old: previous byte size
 * @new: new byte size
 * Return: pointer to the old block
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *p;

	if (!ptr)
		return (malloc(new));
	if (!new)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);

	p = malloc(new);
	if (!p)
		return (NULL);

	old = old < new ? old : new;
	while (old--)
		p[old] = ((char *)ptr)[old];
	free(ptr);
	return (p);
}
