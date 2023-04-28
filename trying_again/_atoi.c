#include "shell.h"

/**
 * _atoi - converts a str to an int
 * @s: the str to convert
 * Return: generated int if success, 0 otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1;
	int output, flag = 0;
	unsigned int res = 0;

	i = 0;
	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}
	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}
