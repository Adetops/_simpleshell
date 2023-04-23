#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that prints "$ " and wait for user to input, then print input
 *
 * Return: always 0
 */
int main(void)
{
	char *chrs;

	chrs = malloc(sizeof(char) * 20);
	printf("$ ");
	scanf("%s", chrs);
	printf("%s\n", chrs);
	free(chrs);

	return (0);
}
