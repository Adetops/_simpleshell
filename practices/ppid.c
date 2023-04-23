#include <stdio.h>
#include <unistd.h>

/**
 * main - main code
 *
 * Return: always 0
 */
int main(void)
{
	pid_t myPid = getppid();

	printf("Hello, World!\n");
	printf("%u\n", myPid);

	return (0);
}
