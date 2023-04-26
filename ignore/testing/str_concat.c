#include "fuji.h"
/**
 * str_concat - concatenates two strings to newly allocated space in memory
 * @s1: string1
 * @s2: string 2 to appended to string1
 * Return: pointer to the concatenated string; NULL otherwise
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	concat_str = malloc((sizeof(char) * i) + (sizeof(char) * j) + 1);
	if (concat_str == NULL)
		exit(0);
	for (i = 0; s1[i] != '\0'; i++)
		concat_str[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++)
		concat_str[i + j] = s2[j];
	concat_str[i + j] = '\0';
	return (concat_str);
}
