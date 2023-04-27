#include "shell.h"
/**
 * utd - source of dest
 * @dest: target
 * @src: source
 * Return: cp chr *
 */
char *utd(char *dest, char *src)
{
int i;

i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
return (dest);
}
/**
 * mcat - jpoins two lines
 * @dest: first
 * @src: second
 * Return:first + second *
 */
char *mcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - locates str
 * @s: str search
 * @c: to char
 * Return: pointer to char*
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * moon - compares strings counts.
 * @s1: first.
 * @s2: second.
 * @n: compared results.
 *
 * Return: either (1) or (0)
 */
int moon(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * wsup - doubles str
 * @str: str
 * Return: nothing
 */
char *wsup(char *str)
{
	size_t len, i;
	char *str2;

	len = finto(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
