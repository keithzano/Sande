#include "shell.h"

/**
 * handle_b - handles our builtin
 * @cmd:parsed cmd
 * @er:deals with last cmd
 * Return: fail (-1) and (0)
 */

int handle_b(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", cd_dir},
		{"env", di_environ},
		{"help", user_help},
		{"echo", echo_bult},
		{"history", historyf_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (ptree(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_check - execute cmnds
 *
 * @cmd:parsed cmd
 * @input: input from user
 * @c:runs when handles aren't found
 * @argv: title of program
 * Return: either --1, 0 or 1
 */
int check_check(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (moon(*cmd, "./", 2) != 0 && moon(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * sign - hand cntrl stroke
 * @sig: available signal
 * Return: nothing
 */
void sign(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
