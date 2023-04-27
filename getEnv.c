#include "shell.h"

/**
 * getEnviron - returns the string array copy of our environ
 * @info: parameter struct
 * Return: always 0
 */
char **getEnviron(info_t *info)
{
	if (!info->environ || info->env_change)
	{
		info->environ = listStr(info->env);
		info->env_change = 0;
	}
	return (info->environ);
}

/**
 * unsetEnv - remove an environ variable
 * @info: structure that contain potential args.
 * @var: string environ variable property
 * Return: 1 on del, 0 otherwise
 */
int unsetEnv(info_t *info, char *var)
{
	list_t *node = info->env;
	char *ptr;
	size_t i = 0;

	if (!node || !var)
		return (0);

	while (node)
	{
		ptr = startWith(node->string, var);
		if (ptr && *ptr == '=')
		{
			info->env_change = delNode(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_change);
}

/**
 * setEnv - initialize a new environ variable or modify an existing one
 * @info: structure containing potential arguments.
 * @var: the string environ var property
 * @val: the string environ var value
 * Return: always 0;
 */
int setEnv(info_t *info, char *var, char *val)
{
	char *buff = NULL;
	list_t *node;
	char *ptr;

	if (!var || !val)
		return (0);

	buff = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, val);
	node = info->env;
	while (node)
	{
		ptr = startWith(node->string, var);
		if (ptr && *ptr == '=')
		{
			free(node->string);
			node->string = buff;
			info->env_change = 1;
			return (0);
		}
		node = node->next;
	}
	appendNode(&(info->env), buff, 0);
	free(buff);
	info->env_change = 1;
	return (0);
}
