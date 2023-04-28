#include "shell.h"

/**
 * _env - prints the current environment
 * @inf: placeholder for potential args
 * Return: always 0.
 */
int _env(info_t *inf)
{
	printList(inf->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: placeholder for potential args
 * @name: env variable name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = startWith(node->string, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setenv - Initialize a new environ car, or modify an existing one
 * @info: placeholder for potential arg
 * Return: always 0
 */
int _setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_input("Incorrect number of arguments\n");
		return (1);
	}
	if (setEnv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenv - Remove an environ var
 * @info: placeholder for potential argument
 * Return: always 0
 */
int _unsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_input("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		unsetEnv(info, info->argv[i]);
	return (0);
}

/**
 * populateEnvList - populates linked list environs
 * @inf: Structure that contains potential args. Used to
 * maintain constant func prototype.
 * Return: always 0
 */
int populateEnvList(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		appendNode(&node, environ[i], 0);
	inf->env = node;
	return (0);
}
