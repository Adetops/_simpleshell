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
	printD(inf->err_count, STDERR_FILENO);
	_input(": ");
	_input(inf->argv[0]);
	_input(": ");
	_input(errstr);
}

/**
 * printD - function that prints a decimal num in base 10 (an integer)
 * @num: the input
 * @fileD: the filedescriptor to write to
 * Return: number of characters printed
 */
int printD(int num, int fileD)
{
	int count = 0, i;
	unsigned int current, _abs_;
	int (*__putchar)(char) = _putchar;

	if (fileD == STDERR_FILENO)
		__putchar = _putchr;
	if (num < 0)
	{
		_abs_ = -num;
		__putchar('-');
		count++;
	}
	else
		_abs_ = num;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar(current + '0');
	count++;

	return (count);
}

/**
 * convert_numb - converter function, a clone to itoa
 * @numb: number
 * @base: base
 * @flag: argument flags
 * Return: string
 */
char *convert_numb(long int numb, int base, int flag)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = numb;

	if (!(flag & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sign = '-';
	}
	array = flag & CONVERT_LWCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * rem_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 * Return: always 0
 */
void rem_comments(char *buff)
{
	int i = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
		i++;
	}
}
