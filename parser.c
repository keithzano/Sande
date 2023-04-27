#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st) != 0)
        return 0;

    return S_ISREG(st.st_mode);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    if (!pathstr)
        return NULL;

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return cmd;
    }

    char *path = strtok(pathstr, ":");
    while (path != NULL)
    {
        char *full_path = malloc(_strlen(path) + _strlen(cmd) + 2);
        if (full_path == NULL)
            return NULL;

        _strcpy(full_path, path);
        _strcat(full_path, "/");
        _strcat(full_path, cmd);

        if (is_cmd(info, full_path))
            return full_path;

        free(full_path);
        path = strtok(NULL, ":");
    }

    return NULL;
}

/**
 * starts_with - checks if a string starts with a prefix
 * @str: the string to check
 * @prefix: the prefix to compare
 *
 * Return: 1 if str starts with prefix, 0 otherwise
 */
int starts_with(const char *str, const char *prefix)
{
    while (*prefix)
    {
        if (*prefix != *str)
            return 0;
        prefix++;
        str++;
    }
    return 1;
}
