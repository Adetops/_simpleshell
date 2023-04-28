#include "shell.h"

/**
 * _varreplace - replaces variables in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int _varreplace(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			_strreplace(&(info->argv[i]),
				_strdup(convert_numb(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			_strreplace(&(info->argv[i]),
				_strdup(convert_numb(getpid(), 10, 0)));
			continue;
		}
		node = nodeStartsWith(info->env, &info->argv[i][1], '=');
		if (node)
		{
			_strreplace(&(info->argv[i]),
				_strdup(_strchr(node->string, '=') + 1));
			continue;
		}
		_strreplace(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * _aliasreplace - replaces an alias in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int _aliasreplace(info_t *info)
{
	int i;
	list_t *node;
	char *ptr;

	for (i = 0; i < 10; i++)
	{
		node = nodeStartsWith(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ptr = _strchr(node->string, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		info->argv[0] = ptr;
	}
	return (1);
}

/**
 * _strreplace - replaces string
 * @old: address of old string
 * @new: new string
 * Return: 1 if replaced, otherwise 0
 */
int _strreplace(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * _ischain - test if current char in buffer is a chain delimiter
 * @info: the parameter struct
 * @buff: the char buffer
 * @ptr: address of current position in buff
 * Return: 1 if chain delimeter, otherwise 0
 */
int _ischain(info_t *info, char *buff, size_t *ptr)
{
	size_t j = *ptr;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		info->cmd_buff_type = CMD_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;
		j++;
		info->cmd_buff_type = CMD_AND;
	}
	else if (buff[j] == ';') /* i.e. end of a command */
	{
		buff[j] = 0;
		info->cmd_buff_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = j;
	return (1);
}

/**
 * _checkchain - checks if chaining should continue based on last status
 * @info: the parameter struct
 * @buff: the char buffer
 * @ptr: address of current position in buff
 * @i: starting position in buff
 * @len: length of buffer
 * Return: nothing
 */
void _checkchain(info_t *info, char *buff, size_t *ptr, size_t i, size_t len)
{
	size_t j = *ptr;

	if (info->cmd_buff_type == CMD_AND)
	{
		if (info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buff_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	*ptr = j;
}
