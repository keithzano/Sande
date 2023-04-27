#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++) {
        *(s + i) = b;
    }

    return s;
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    if (pp == NULL) return;

    char **curr = pp;
    while (*curr != NULL) {
        free(*curr);
        *curr = NULL;
        curr++;
    }

    free(pp);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    if (ptr != NULL) {
        char *old_ptr = ptr;
        for (unsigned int i = 0; i < old_size && i < new_size; i++) {
            *((char*)new_ptr + i) = *(old_ptr + i);
        }

        free(ptr);
    }

    return new_ptr;
}
