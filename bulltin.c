#include "shell.h"
/**
 * 
 * close_obul - exists our shell
 * @cmd: records parsed cmd
 * @input: user inp
 * @argv: our program name
 * @c: check count
 * Return: void or exits shell
 */
void  close_obul(char **cmd, char *input, char **argv, int c)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (sala(cmd[1][i++]) != 0)
		{
			_proerr(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}


/**
 * cd_dir - cd to the next dir
 * @cmd: records parsed cmd
 * @er: goes one command back
 * Return: 0 is success and 1 failure
 */
int cd_dir(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (ptree(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * di_environ - provides env variable
 * @cmd:records parsed cmd
 * @er:goes one command back
 * Return:Always 0
 */
int di_environ(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = finto(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

int user_help(char **cmd, __attribute__((unused))int er)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_bult - handles echo
 * @st: last command executed
 * Return: returns 0 or execute echo
 */
int echo_bult(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (moon(cmd[1], "$?", 2) == 0)
	{
		prt_num(st);
		PRINTER("\n");
	}
	else if (moon(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (moon(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (prt_echo(cmd));

	return (1);
}
