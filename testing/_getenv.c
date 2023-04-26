#include "fuji.h"

/**
 * _getenv - get an environmental variable
 * @name: name of env var
 * @env: list of env var
 * Return: pointer to env var
 */
char *_getenv(const char *name, char **env)
{
	int i, j;
	int res, len;

	i = j = 0;
	while (env[i] != NULL)
	{
		res = _strcmp(name, (const char *)env[i]);
		if (res == 1)
		{
			len = _strlen(env[i]);
			while (env[i][j] != '=')
				j += 1;
			len -= j;
			return (env[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}
