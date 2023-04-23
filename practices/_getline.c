#include <stdio.h>

/**
 * _getline - program that reads an entire line from stream
 * @lineptr: pointer to the buffer address
 * @n: number of characters read
 * @stream: buffer stream to read from
 *
 * Return: n
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	n = 0;

	*lineptr = &stream;
	if ((*lineptr)[n] == "\0")
	{
		break;
	}




	return (n);
}

/**
 * main - readline
 *
 * Return: always 0
 */
int main(void)
{
	char *line = NULL;
	size_t n;
	
	printf("$ ");
	_getline(&line, &n, stdin);
	printf("%s\n", line);

	return (0);
}
