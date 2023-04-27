#include "shell.h"

/**
 * _history - displays the history list, a cmd per lin,
 * preceded with line numbers, starting at 0.
 * @inf: placeholder for potential arg
 * Return: always 0
 */
int _history(info_t *inf)
{
	prList(inf->hist);
	return (0);
}

/**
 * aliasUnset - sets alias to string
 * @inf: parameter struct
 * @str: the string alias
 * Return: Always 0, 1 otherwise
 */
int aliasUnset(info_t *inf, char *str)
{
	char *ptr, chr;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	chr = *ptr;
	*ptr = 0;
	ret = delNode(&(inf->alias),
		getNode(inf->alias, nodeStartsWith(inf->alias, str, -1)));
	*ptr = chr;
	return (ret);
}

/**
 * aliasSet - sets alias to a string
 * @inf: parameter struct
 * @str: the string alias
 * Return: always 0, 1 otherwise
 */
int aliasSet(info_t *inf, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (aliasUnset(inf, str));
	aliasUnset(inf, str);
	return (appendNode(&(inf->alias), str, 0) == NULL);
}

/**
 * aliasPrint - prints the alias string
 * @node: node of the alias
 * Return: Always 0, otherwise 1
 */
int aliasPrint(list_t *node)
{
	char *ptr = NULL, *a = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (a = node->str; a <= ptr; a++)
			_putchr(*a);
		_putchr('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - mimics the alias builtin (man alias)
 * @inf: structure that contain potential args, to
 * maintain constant function prototype
 * Return: Always 0
 */
int _alias(info_t *inf)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			aliasPrint(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{
		ptr = _strchr(inf->argv[i], '=');
		if (ptr)
			aliasSet(inf, inf->argv[i]);
		else
			aliasPrint(nodeStartsWith(inf->alias, inf->argv[i], '='));
	}

	return (0);
}
