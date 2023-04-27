#include "shell.h"

/**
 * hsh - main shell loop
 * @info: parameter and return info struct
 * @arv: the argument vector from main()
 * Return: 0 on successs, 1 on error, error code
 */
int hsh(info_t *info, char **arv)
{
	ssize_t r = 0;
	int builtinRet = 0;

	while (r != -1 && builtinRet != -2)
	{
		clrInfo(info);
		if (interactive(info))
			_puts("$ ");
		_putchr(BUFF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			setInfo(info, arv);
			builtinRet = findBuiltin(info);
			if (builtinRet == -1)
				findCmd(info);
		}
		else if (interactive(info))
			_putchr('\n');
		freeInfo(info, 0);
	}
	writeHist(info);
	freeInfo(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtinRet == -2)
	{
		if (info->err_numb == -1)
			exit(info->status);
		exit(info->err_numb);
	}
	return (builtinRet);
}

/**
 * findBuiltin - finds a builtin command
 * @info: the parameter & return info struct
 * Return: -1 if builtin not found,
 * 0 if builtin executed successfully,
 * 1 if builtin found but execution not successful,
 * -2 if builtin signals exit()
 */
int findBuiltin(info_t *info)
{
	int i, builtinRet = -1;
	builtin_tab builtinlb[] = {
		{"exit", _exits},
		{"env", _env},
		{"help", _help},
		{"history", _history},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", chDir},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (i = 0; builtinlb[i].type; i++)
		if (_strcmp(info->argv[0], builtinlb[i].type) == 0)
		{
			info->err_count++;
			builtinRet = builtinlb[i].func(info);
			break;
		}
	return (builtinRet);
}

/**
 * findCmd - finds a command in PATH
 * @info: the parameter and return info struct
 *
 * Return: nothing
 */
void findCmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->err_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = findPath(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		forkCmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && isCmd(info, info->argv[0]))
			forkCmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_err(info, "not found\n");
		}
	}
}

/**
 * forkCmd - forks an exec thread to run cmd
 * @info: parameter and return info struct
 * Return: nothing
 */
void forkCmd(info_t *info)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		/* TODO: Put Error Function */
		perror("Error:");
		return;
	}
	if (my_pid == 0)
	{
		if (execve(info->path, info->argv, getEnviron(info)) == -1)
		{
			freeInfo(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_err(info, "Permission denied\n");
		}
	}
}
