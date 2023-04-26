#include "fuji.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1 to be compared to string 2
 * @s2: string 2 to be compared to string 1
 * Return: integer < 0 if string 1 first unmatched character ASCII value is
 * less than string 2; integer > 0 if first unmatched character ASCII value
 * is greater; 0 if strings are equal
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;

	while (s1[i] == s2[i])
		i += 1;
	if (s1[i] == '\0')
		return (1);
	else
		return (-1);
}
