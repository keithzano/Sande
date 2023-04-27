#include "shell.h"
/**
 * access_file - accesses our file
 * @filename: target file
 * @argv: title
 * Return: return (0) or (-1)
 */

void access_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		sort_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * sort_file - sorts out our file
 * @line: end of of line sort
 * @counter: logs errors
 * @fp: filename
 * @argv: title of program
 * Return : void
 */
void sort_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);

		if (moon(cmd[0], "exit", 4) == 0)
		{
			close_bulf(cmd, line, fp);
		}
		else if (check_b(cmd) == 0)
		{
			st = handle_b(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_check(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * close_bulf - Exit Shell Case Of File
 * @cmd: parsed cmd
 * Return : end of line
 */
void close_bulf(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (sala(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}
