#include "fuji.h"

/**
 * _memcpy - copies memory area
 * @dest: address of memory to be filled
 * @src: constant byte to be filled
 * @n: number of bytes to be copied from src to dest
 * Return: address of pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
{
		dest[i] = src[i];
}
	return (dest);
}
