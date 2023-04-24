#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;

	printf("I will understand how you work soon!\n");
	pid = fork();

	if (pid == -1)
	{
		printf("Error! The recent operation was unsuccessful\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("I am the child process! I am running currently.\n");
		printf("You cannot chase me out until I am done here!\n");
		return (0);
	}
	else
	{
		printf("Don't mind my child, I'm his parent.\n");
		printf("%u, we need to get going, do quick!\n", pid);
		wait(&status);
		printf("My child %u is through with status %d, bye everyone!\n", pid, WEXITSTATUS(status));
	}
	return (0);
}
