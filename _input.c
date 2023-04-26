#include "shell.h"

/**
 * _input - prints an input string
 * @str: the string to print
 * Return: nothing
 */
void _input(char *str)
{
	int i = 0;

	if (str)
	{
		while (str[i] != '\0')
		{
			_putchr(str[i]);
			i++;
		}
	}
}

/**
 * _putchr - writes the char c to stderr
 * @c: the char to write
 * Return: 1 if success
 * if error, -1 is returned and eerno is set appropriately
 */
int _putchr(char c)
{
	static int i;
	static char buff[WR_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WR_BUFF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}

/**
 * _putfileD - writes the character c to given file Descriptor
 * @c: the character to write
 * @fd: The file descriptor to write to
 * Return: 1 if success
 * if error, -1 is returned and eerno is set appropriately
 */
int _putfileD(char c, int fd)
{
	static int i;
	static char buff[WR_BUFF_SIZE];

	if (c == BUFF_FLUSH || i == WR_BUFF_SIZE)
	{
		write(fd, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}

/**
 * _putsfileD - prints an input sprint
 * @str: the string to print
 * @fd: the file descriptor to write to
 * Return: the number of char input
 */
int _putsfileD(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfileD(*str++, fd);
	}
	return (i);
}
