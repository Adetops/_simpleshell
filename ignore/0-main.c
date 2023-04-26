#include <stdio.h>

int _add(int a, int b);

/**
 * _add - function that add two integers and returns the result.
 * @a: first integer
 * @b: second integer
 *
 * Return: sum
 */
int _add(int a, int b)
{
	return (a + b);
}

/**
 * main - main code
 *
 * Return: always 0
 */
int main(void)
{
	printf("The sum of 6 and 18 is: %d\n", _add(6, 18));

	return (0);
}
