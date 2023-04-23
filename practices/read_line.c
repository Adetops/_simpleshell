#include <stdio.h>
#include <stdlib.h>

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
	getline(&line, &n, stdin);
	printf("%s", line);
	free(line);

	return (0);
}
