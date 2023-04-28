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
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);

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
	char *s = dest;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[count1] != '\0' && count1 < n)
	{
		dest[count] = src[count1];
		count++;
		count1++;
	}
	if (count1 < n)
		dest[count] = '\0';
	return (s);
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
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _strlen - returns the length of a string
 * @str: string to check
 * Return: length
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}
