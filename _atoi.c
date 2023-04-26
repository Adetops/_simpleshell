#include "shell.h"

/**
 * interactive - returns 1 if shell is in interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfileD <= 2);
}

/**
 * _delim - checks if char is a delimiter
 * @c: the char to check
 * @delim: the delimiter str
 * Return: 1 if true, 0 if false
 */
int _delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic characters
 * @c: the char to input
 * Return: 1 if c is an alphabet, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a str to an int
 * @s: the str to convert
 * Return: generated int if success, 0 otherwise
 */
int _atoi(char *s);
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
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
