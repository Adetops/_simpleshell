#include "shell.h"

/**
 * listLen - determines the lenth of a linked list
 * @head: pointer to the first node
 * Return: list  size
 */
size_t listLen(const list_t *head)
{
	size_t i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * listStr - returns an array of strings of the list_t strings
 * @head: pointer to the first node
 * Return: array of strings
 */
char **listStr(list_t *head)
{
	list_t *node = head;
	size_t i, j = listLen(head);
	char **strs;
	char *str;

	if (!head || !j)
		return (NULL);
	strs = malloc(sizeof(char *) * (j + 1));
	if (!strs)
		return (NULL);
	for (j = 0; node; node = node->next, j++)
	{
		str = malloc(_strlen(node->string) + 1);
		if (!str)
		{
			for (i = 0; i < j; i++)
				free(strs[i]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->string);
		strs[j] = str;
	}
	strs[j] = NULL;
	return (strs);
}

/**
 * prList - prints all elements of a linked list
 * @head: pointer to the first node
 * Return: list size
 */
size_t prList(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_numb(head->numb, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->string ? head->string : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * nodeStartsWith - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @chr: the next character after prefix to match
 * Return: match node or null
 */
list_t *nodeStartsWith(list_t *node, char *prefix, char chr)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = startWith(node->string, prefix);
		if (ptr && ((chr == -1) || (*ptr == chr)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * getNode - gets the index of a node
 * @head: head pointer
 * @node: node pointer
 * Return: index of node or -1
 */
ssize_t getNode(list_t *head, list_t *node)
{
	size_t i;

	i = 0;
	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
