#include "fuji.h"

/**
 * _strcmp2 - compares two strings
 * @s1: string 1 to be compared to string 2
 * @s2: string 2 to be compared to string 1
 * Return: integer < 0 if string 1 first unmatched character ASCII value is
 * less than string 2; integer > 0 if first unmatched character ASCII value
 * is greater; 0 if strings are equal
 */
int _strcmp2(const char *s1, const char *s2)
{
	int i, result;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		result = s1[i] - s2[i];
		if (result == 0)
			continue;
		else
			break;
	}
	if (s1[i] == '\0' || s2[i] != '\0')
		result = s1[i] - s2[i];

	return (result);
}
