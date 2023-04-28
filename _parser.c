#include "shell.h"

/**
 * isCmd - determines if a file is an executable or not
 * @info: info struct
 * @path: the path to the file
 * Return: 1 if true, 0 otherwise
 */
int isCmd(info_t *info, char *path)
{
	struct stat str;

	(void)info;
	if (!path || stat(path, &str))
		return (0);
	if (str.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * dupChr - duplicate characters
 * @path: the path to the characters
 * @start: indicate the index to start from
 * @end: the index to stop duplication
 * Return: a pointer to the new buffer
 */
char *dupChr(char *path, int start, int end)
{
	static char buff[1024];
	int i, k;

	i = 0;
	k = 0;
	for (k = 0, i = start; i < end; i++)
	{
		if (path[i] != ':')
		{
			buff[k++] = path[i];
		}
	}
	buff[k] = 0;
	return (buff);
}

/**
 * findPath - find given command in the specified path string
 * @info: info struct
 * @path: path string to look through
 * @cmd: command to find
 * Return: full path of the command if found, NULL otherwise
 */
char *findPath(info_t *info, char *path, char *cmd)
{
	int currentPosition = 0, i = 0;
	char *pat;

	if (!path)
		return (NULL);
	if ((_strlen(cmd) > 2) && startWith(cmd, "./"))
	{
		if (isCmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!path[i] || path[i] == ':')
		{
			pat = dupChr(path, currentPosition, i);
			if (!*pat)
				_strcat(pat, cmd);
			else
			{
				_strcat(pat, "/");
				_strcat(pat, cmd);
			}
			if (isCmd(info, pat))
				return (pat);
			if (!path[i])
				break;
			currentPosition = i;
		}
		i++;
	}
	return (NULL);
}
