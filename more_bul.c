#include "shell.h"

/**
 * historyf_dis - gives out exexuted cmds
 * @c:parsed cmd
 * @s:last cmnd (up)
 * Return: either (0) or (1)
 */
int historyf_dis(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = bob(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
 * prt_echo - prts echo
 * @cmd: parsed cmds
 * Return: (0) or (-1) ->Fail
 */
int prt_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
