#include "shell.h"

/**
 * main - actual shell.
 * @argc: arg counts.
 * @argv: argv.
 * Return: close by cmnd.
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		access_file(argv[1], argv);
	signal(SIGINT, sign);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = getl();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (ptree(cmd[0], "exit") == 0)
		{
			close_obul(cmd, input, argv, counter);
		}
		else if (check_b(cmd) == 0)
		{
			st = handle_b(cmd, st);
			release_mem(cmd, input);
			continue;
		}
		else
		{
			st = check_check(cmd, input, counter, argv);

		}
		release_mem(cmd, input);
	}
	return (statue);
}
/**
 * check_b - checks b
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_b(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (ptree(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * crea_env - creates env var
 * @envi: array of var
 * Return: Void
 */
void crea_env(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = wsup(environ[i]);
	envi[i] = NULL;
}
