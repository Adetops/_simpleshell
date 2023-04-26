#include "fuji.h"
/**
* err_exit - prints out an error and exits
* @argv: arguments
* @status: exits with this status
*/

void err_exit(char *argv, int status)
{
	(void)status;
	perror(argv);
	exit(0);
}
