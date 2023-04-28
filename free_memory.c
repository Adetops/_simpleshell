#include "shell.h"

/**
 * frees - frees a pointer memory and points the address to NULL
 * @ptr: address of the pointer to free
 * Return: 1 if frees, 0 otherwise
 */
int frees(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
