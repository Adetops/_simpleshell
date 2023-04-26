#include "fuji.h"

/**
 * signal_handler - reprints prompt when signal ctrl+C is captured
 * @signo: signal number
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "Fuji$ ", 6);
	}
}
