#include "shell.h"

/**
 * prompt - display ($)
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - counts shell loops
 * @input:from prompt
 * @counter:counts loops
 * @argv:title of prgram
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = bob(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
