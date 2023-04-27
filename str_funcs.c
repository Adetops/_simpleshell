#include "shell.h"

/**
 * *_strncpy - function that copies a string
 * @dest: destination
 * @src: source
 * @n: number of bytes of src copied
 * Return: pointer to the string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 * *_strncat - function that concatenates two strings
 * @dest: destination
 * @src: source
 * @n: number of bytes used from src
 *
 * Return: pointer to the dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int count = 0, count1 = 0;

	while (*(dest + count) != '\0')
	{
		count++;
	}
	while (count1 < n)
	{
		*(dest + count) = *(src + count1);
		if (*(src + count) == '\0')
			break;
		count++;
		count1++;
	}
	return (dest);
}

/**
 * *_strchr - locates a character in a string
 * @s: pointer to a string
 * @c: character to locate
 * Return: pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	while (1)
	{
		if (*s == c)
			return (s);
		if (*s == 0)
			return (0);
		s++;
	}
}
