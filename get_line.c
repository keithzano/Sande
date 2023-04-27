
#include "shell.h"

/**
* getl - get user inpts
* Return: result
*/
char *getl()
{
int i, buffsize = BUFSIZE, rd;
char c = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = relocate(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	tag_handl(buff);
	return (buff);
}

/**
 * tag_handl - deletes chars after pound sign
 * @buff: input;
 * Return:void
 */
void tag_handl(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
