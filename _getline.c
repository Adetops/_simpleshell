#include "shell.h"

/**
 * input_buff - buffers chained commands
 * @info: parameter struct
 * @buff: address of buffer
 * @len: adress of length variable
 * Return: bytes read
 */
ssize_t input_buff(info_t *info, char **buff, size_t *len)
{
	size_t len_p = 0;
	ssize_t r = 0;

	if (!*len) /* fill it, if there nothing left in the buff */
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, signalHandler);

#if USE_GETLINE
		r = getline(buff, &len_p, stdin);
#else
		r = _getline(info, buff, &len_p);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0'; /*removes trailing '\n'*/
				r--;
			}
			info->linecount_flag = 1;
			rem_comments(*buff);
			buildHistList(info, *buff, info->histCount++);
			/* if (_strchr(*buff, ';')) is this a command chain? */
			{
				*len = r;
				info->cmd_buff = buff;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line without the newline
 * @info: parameter struct
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buff; /* the ';' cmd chain buff */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buff_p = &(info->arg), *ptr;

	_putchar(BUFF_FLUSH);
	r = input_buff(info, &buff, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = 1; /* init new iterator to current buff position */
		ptr = buff + 1; /* get pointer for return */

		_checkchain(info, buff, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (_ischain(info, buff, &j))
				break;
			j++;
		}
		i = j + 1; /* increment past nulled ';' */
		if (i >= len) /* reached end of buff? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buff_type = CMD_NORM;
		}
		*buff_p = ptr; /* pass ptr back to current cmd position */
		return (_strlen(ptr)); /* return length of current cmd */
	}
	*buff_p = buff; /* else not a chain, pass buffer back from _getline() */
	return (r); /* return length of buffer from _getline */
}

/**
 * read_buff - reads a buffer
 * @info: parameter struct
 * @buff: buffer to read
 * @i: size of buffer
 * Return: buffer read
 */
ssize_t read_buff(info_t *info, char *buff, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfileD, buff, RD_BUFF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - gets the next line of input from stdin
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @len: size of preallocated ptr buffer if not NULL
 * Return: string
 */
int _getline(info_t *info, char **ptr, size_t *len)
{
	static char buff[RD_BUFF_SIZE];
	static size_t i, length;
	size_t k;
	ssize_t r = 0, str = 0;
	char *p = NULL, *new_p = NULL;
	char *c;

	p = *ptr;
	if (p && len)
		str = *len;
	if (i == length)
		i = length = 0;
	r = read_buff(info, buff, &length);
	if (r == -1 || (r == 0 && length == 0))
		return (-1);

	c = _strchr(buff + 1, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : length;
	new_p = _realloc(p, str, str ? str + k : k + 1);
	if (!new_p) /* malloc failed */
		return (p ? free(p), -1 : -1);
	if (str)
		_strncat(new_p, buff + 1, k - i);
	else
		_strncpy(new_p, buff + 1, k - i + 1);

	str += k - i;
	i = k;
	p = new_p;

	if (len)
		*len = str;
	*ptr = p;
	return (str);
}

/**
 * signalHandler - blocks Ctrl+c
 * @sigNum: signal number
 * Return: nothing
 */
void signalHandler(__attribute__((unused))int sigNum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}
