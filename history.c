#include "shell.h"

/**
 * getHistFile - gets the history file
 * @inf: parameter struct
 * Return: allocated str that contains hist file
 */
char *getHistFile(info_t *inf)
{
	char *buff, *dir;

	dir = _getenv(inf, "HOME=");
	if (!dir)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * writeHist - creates a file || appends to an existing file
 * @info: the parameter struct
 * Return: 1 on success, -1 otherwise
 */
int writeHist(info_t *info)
{
	ssize_t fileD;
	list_t *node = NULL;
	char *fName = getHistFile(info);

	if (!fName)
		return (-1);

	fileD = open(fName, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fName);
	if (fd == -1)
		return (-1);
	for (node = info->hist; node; node = node->next)
	{
		_putsfileD(node->string, fileD);
		_putfileD('\n', fileD);
	}
	_putfileD(BUFF_FLUSH, fileD);
	close(fileD);
	return (1);
}

/**
 * readHist - reads history from file
 * @inf: parameter struct
 * Return: hist count on success, 0 otherwise
 */
int readHist(info_t *inf)
{
	int i = 0, count = 0, last = 0;
	char *buff = NULL, *fName = getHistFile(info);
	ssize_t fileD, rdLen, fSize = 0;
	struct stat str;

	if (!fName)
		return (0);
	fileD = open(fName, o_RDONLY);
	free(filename);
	if (fileD == -1)
		return (0);
	if (!fstat(fileD, &str))
		fSize = str.str_size;
	if (fSize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fSize + 1));
	if (!buff)
		return (0);
	rdLen = read(fileD, buff, fSize);
	buff[fSize] = 0;
	if (rdLen <= 0)
		return (free(buff), 0);
	close(fileD);
	while (i < fSize)
	{
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			buildHistList(info, buff + last, count++);
			last = i + 1;
		} i++;
	}
	if (last != i)
		buildHistList(info, buff + last, count++);
	free(buff);
	info->histCount = count;
	while (info->histCount-- >= HIST_MAX)
		delNode(&(info->hist), 0);
	reNumbHist(info);
	return (info->histCount);
}

/**
 * buildHistList - adds entry to a history linked list
 * @info: structure that contains potential args.
 * @buff: the buffer
 * @count: history line count
 * Return: always 0
 */
int buildHistList(info_t *info, char *buff, int count)
{
	list_t *node = NULL;

	if (info->hist)
		node = info->hist;
	appendNode(&node, buff, count);
	if (!info->hist)
		info->hist = node;
	return (0);
}

/**
 * reNumbHist - function that renumbers a history linked list after a change.
 * @inf: parameter struct
 * Return: the new history count
 */
int reNumbHist(info_t *inf)
{
	list_t *node = info->hist;
	int i = 0;

	while (node)
	{
		node->numb = i++;
		node = node->next;
	}
	return (info->histCount = i);
}
