#include "shell.h"

/**
 * addNode - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: string field of node
 * @num: node index used by history
 * Return: list size
 */
list_t *addNode(list_t **head, const char *str, int num)
{
	list_t *newHead;

	if (!head)
		return (NULL);
	newHead = malloc(sizeof(list_t));
	if (!newHead)
		return (NULL);
	_memset((void *)newHead, 0, sizeof(list_t));
	newHead->numb = num;
	if (str)
	{
		newHead->string = _strdup(str);
		if (!newHead->string)
		{
			free(newHead);
			return (NULL);
		}
	}
	newHead->next = *head;
	*head = newHead;
	return (newHead);
}

/**
 * appendNode - add a node at the end of the linked list
 * @head: address of the pointer to the first node
 * @str: str field of node
 * @num: node index used by histo
 * Return: list size
 */
list_t *appendNode(list_t **head, const char *str, int num)
{
	list_t *newnode, *node;

	if (!head)
		return (NULL);
	node = *head;
	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);
	_memset((void *)newnode, 0, sizeof(list_t));
	newnode->numb = num;
	if (str)
	{
		newnode->string = _strdup(str);
		if (!newnode->string)
		{
			free(newnode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newnode;
	}
	else
		*head = newnode;
	return (newnode);
}

/**
 * prList - prints only the str element of a list_t linked list
 * @head: pointer to the first node
 * Return: list size
 */
size_t printList(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->string ? head->string : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * delNode - deletes node at the given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 * Return: 1 on success, 0 if failed
 */
int delNode(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->string);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->string);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * freeList - frees all node of a list
 * @head: address of pointer to first node
 * Return: nothing
 */
void freeList(list_t **head)
{
	list_t *node, *nextnode, *h;

	if (!head || !*head)
		return;
	h = *head;
	node = h;
	while (node)
	{
		nextnode = node->next;
		free(node->string);
		free(node);
		node = nextnode;
	}
	*head = NULL;
}
