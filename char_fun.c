#include "shell.h"

/**
 * _putchar - writes the character c to stdout.
 * @c: chracter to print.
 * Return: 1 on success.
 * 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * copys - cp string characters
 * @dest: dest
 * @src: source
 * @n: int recorded
 * Return: 1 on success
 */

char *copys(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * finto - size of string
 * @s:char
 * Return:int
 */

int finto(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _atoi - int conversion
 * @s: our control string
 * Return: returns an int
 */
int _atoi(char *s)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _place - outputs a string character
 * @str: pointer to a character
 * return: return is empty
 */
void _place(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
_putchar('\n');
return;
}
