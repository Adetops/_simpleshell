#include "shell.h"

/**
 * _exits - exits the shell
 * @inf: structure that contains potential args,
 * used to maintain constant func prototype
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _exits(info_t *inf)
{
	int exitCheck;

	if (inf->argv[1])
	{
		exitCheck = err_atoi(inf->argv[1]);
		if (exitCheck == -1)
		{
			inf->status = 2;
			print_err(inf, "Number out of coverage: ");
			_input(inf->argv[1]);
			_putchr('\n');
			return (1);
		}
		inf->err_numb = err_atoi(inf->argv[1]);
		return (-2);
	}
	inf->err_numb = -1;
	return (-2);
}

/**
 * chDir - changes from the current dir to the specified dir (same process).
 * @inf: Structure that contain potential arg, to maintain const func prototype
 * Return: 0 if success
 */
int chDir(info_t *inf)
{
	int ret;
	char *s, *dir, buffer[1024];

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		dir = _getenv(inf, "HOME=");
		if (!dir)
			ret = /* TODO: what should this be? */
				chdir((dir = _getenv(inf, "PWD=")) ? dir : "/");
		else
			ret = chdir(dir);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		ret = /* TODO: what should this be? */
			chdir((dir = _getenv(inf, "OLDPWD=")) ? dir : "/");
	}
	else
		ret = chdir(inf->argv[1]);
	if (ret == -1)
	{
		print_err(inf, "can't cd into ");
		_input(inf->argv[1]), _putchr('\n');
	}
	else
	{
		setEnv(inf, "OLDPWD", _getenv(inf, "PWD="));
		setEnv(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - that explains a cmd or func
 * @inf: the cmd or func to explain
 * Return: Always 0
 */
int _help(info_t *inf)
{
	char **arg_arr;

	arg_arr = inf->argv;
	_puts("help func called: function not yet implemented \n");
	if (0)
		_puts(*arg_arr);

	return (0);
}
