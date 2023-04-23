#include <stdio.h>

/**
 * main - program that prints all the arguments without using 'ac'
 *
 * Return: always 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
