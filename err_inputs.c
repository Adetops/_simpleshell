#include "shell.h"

/**
 * err_atoi - converts a string to an integer
 * @str: the string to convert
 * Return: 0 if no string, converted number if there is, -1 on error
 */
int err_atoi(char *str)
{
	unsigned long int res = 0;
	int i = 0;

	if (*str == '+')
		str++; /* TODO: why does this make main return 255? */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += (str[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_err - prints an error message
 * @inf: parameter for return info structure
 * @errstr: specified error string
 * Return: 0 if no string, converted number if there is, -1 on error
 */
void print_err(info_t *inf, char *errstr)
{
	_input(inf->fName);
	_input(": ");
	printD(inf->line_count, STDERR_FILENO);
	_input(": ");
	_input(inf->argv[0]);
	_input(": ");
	_input(errstr);
}

/**
 *
