#include "shell.h"

/**
 * clrInfo - initializes info_t struct
 * @info: struct address
 * Return: nothing
 */
void clrInfo(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * setInfo - initializes info_t struct
 * @info: struct address
 * @arv: argument vector
 * Return: nothing
 */
void setInfo(info_t *info, char **arv)
{
	int i = 0;

	info->fName = arv[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		_aliasreplace(info);
		_varreplace(info);
	}
}

/**
 * freeInfo - frees info_t struct fields
 * @info: struct address
 * @all: true if all fields are to be freed
 * Return: nothing
 */
void freeInfo(info_t *info, int all)
{
	_free(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buff)
			free(info->arg);
		if (info->env)
			freeList(&(info->env));
		if (info->hist)
			freeList(&(info->hist));
		if (info->alias)
			freeList(&(info->alias));
		_free(info->environ);
			info->environ = NULL;
		frees((void **)info->cmd_buff);
		if (info->readfileD > 2)
			close(info->readfileD);
		_putchar(BUFF_FLUSH);
	}
}
