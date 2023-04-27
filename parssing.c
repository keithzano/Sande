#include "shell.h"

/**
 * parse_cmd - inpt line
 * @input: feed parsed cmd
 * Return: array of char
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtokn(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtokn(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
