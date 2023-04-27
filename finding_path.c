#include "shell.h"

/**
 * path_cmd -  searches cmnds
 * @cmd: parsed inputs
 * Return: either (1) , or (0)
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtokn(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = wsup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtokn(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * build - run and build cmd
 * @token: exc cmd
 * @value: dir with cmd
 *
 * Return: return full path or NULL
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = finto(value) + finto(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = mcat(cmd, value);
	cmd = mcat(cmd, "/");
	cmd = mcat(cmd, token);

	return (cmd);
}
/**
 * _getenv - locates env var by name
 * @name: env name
 * Return: returns env or name
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = finto(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (moon(name, environ[i], nl) == 0)
		{
			vl = finto(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
