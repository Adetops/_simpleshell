#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - main code to test my understanding of fork() and wait()
 *
 * Return: always 0
 */
int main(void)
{
	int status;
	pid_t pid;
	int a, b;

	printf("I want child process to do something other than printing\n");

	pid = fork();

	if (pid == -1)
	{
		perror("There's an error\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("Hey! I'm the child process. I'm here for fun.\n");
		a = 20;
		b = 5;
		printf("The sum of a and b is: %d\n", a + b);
		printf("The product of a and b is: %d\n", a * b);
		printf("My parent cannot do what I did, see?!\n");
		return (a / b);
	}
	else
	{
		printf("This child has started with his troubles again!\n");
		printf("The addition is %d and product is %d\n", a + b, a * b);
		wait(&status);
		printf("I can't just help but wait for you %u\n", pid);
		printf("%u's exit status is %d.\n", pid, WEXITSTATUS(status));
	}

	return (0);
}
