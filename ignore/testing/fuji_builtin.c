#include "fuji.h"

/**
 * fuji_env - prints environmental variable
 * @args: array of arguments
 * @env: array of env vars
 * Return: success: 1
 */
int fuji_env(char **args, char **env)
{
	int i, len;

	i = 0;
	while (env[i] != NULL)
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_array(args);
	return (1);
}

/**
 * fuji_exit - exits the shells
 * @args: array of arguments
 * @env: array of env vars
 * Return: success: 1
 */
int fuji_exit(char **args, char **env)
{
	int status;
	(void)env;

	status = 0;
	if (args[1])
		status = _atoi(args[1]);
	free_array(args);
	exit(status);
}
/**
 * fuji_built - checks for built-in commands and execute them
 * @args: array of arguments
 * @env: array of env vars
 * Return: success: 1
 */
int fuji_built(char **args, char **env)
{
	built_t b_ins[] = {
		{"env", fuji_env},
		{"exit", fuji_exit},
		{NULL, NULL}
	};
	int i;

	if (args[0] == NULL)
		return (0);
	for (i = 0; i < 2; i++)
	{
		if (_strcmp2(args[0], b_ins[i].cmd) == 0)
		{
		return (b_ins[i].f(args, env));
			break;
		}
	}
	return (0);
}
