#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
    int freed = 0;

    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        freed = 1;
    }

    return freed;
}
