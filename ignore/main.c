#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 if success, otherwise 1
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fileD = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fileD)
		: "r" (fileD));

	if (ac == 2)
	{
		fileD = open(av[1], O_RDONLY);
		if (fileD == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_input(av[0]);
				_input(": 0: Can't open ");
				_input(av[1]);
				_putchr('\n');
				_putchr(BUFF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfileD = fileD;
	}
	populateEnvList(info);
	readHistry(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
