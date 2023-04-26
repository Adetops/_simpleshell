#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - using execve()
 *
 * Return: always 0.
 */
int main(void)
{
	char *args[] = {"../../usr/bin/ls", "ls", "-l", NULL};
	pid_t pid;

	printf("I hope this works!\n");

	pid = fork();
	if (pid < 0)
	{
		printf("Fork function failed!\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("The child is about to run\n");
		execve(args[0], args, environ);
		return (0);
	}
	else
	{
		wait(NULL);
		printf("The parent is here again!\n");
	}

	return (0);
}
