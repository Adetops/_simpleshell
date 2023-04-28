#include "shell.h"

/**
 * startWith - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 * Return: address of next char of haystact or NULL
 */
char *startWith(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: pointer to dest buff
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strcmp - function that compares two strings
 * @s1: first input string
 * @s2: second input string
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strcpy - copies the string pointed to by src including the terminating '\0'
 * to the buffer pointed to by dest
 * @dest: the destination string
 * @src: the source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
