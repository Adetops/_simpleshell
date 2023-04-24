#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - split a string and return an array of each word
 *
 * Return: always 0
 */
int main(void)
{
/*	char string[] = "My name is Heritage ADELEKE."; */
	char delim[] = " ";

	char *line = NULL;
	size_t n;
	char *string;
	unsigned i = 0;

	getline(&line, &n, stdin);
	while (line[i])
	{
		if (i == 0)
		{
			string = strtok(line, delim);
			printf("%s\n", string);
		}
		string = strtok(NULL, delim);
		printf("%s", string);
		i++;
	}
	free(line);

	return (0);
}
