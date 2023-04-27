#include "shell.h"
/**
 *  _proerr - function prts error
 * @argv: title of program
 * @c: error accounts
 * @cmd: cmnds
 * Return: nothing
 */
void _proerr(char **argv, int c, char **cmd)
{
	char *er = bob(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
