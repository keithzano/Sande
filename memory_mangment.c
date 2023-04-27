#include "shell.h"

/**
 **relocate -  releases malloc.
 *@ptr: our pointer.
 *@old_size: current pointer.
 *@new_size: new pointer in file.
 *Return: void or nothing
 */
void *relocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		sunray(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		mcopy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * release_mem - frees unused mem.
 * @cmd:points to arr.
 * @line:points to char.
 * Return: nothing.
 */
void release_mem(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * mcopy - bytes copy
 * @dest: points to dest
 * @src: points to source
 * @n: desired cp size
 *Return: nothing
 */
char *mcopy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * sunray - sorts out bytes
 * @a:points to othing
 * @el: just a number interger
 * @len:number of chars
 *Return: nothing
 */
void *sunray(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc -  allocation function
 * @size: just size
 * Return: nothing
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
