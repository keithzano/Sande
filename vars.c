#include "shell.h"

int is_chain(info_t *info, char *buf, size_t *p)
{
    size_t j = *p;
    char current = buf[j];
    char next = buf[j + 1];

    if (current == '|' && next == '|') {
        buf[j] = 0;
        j++;
        info->cmd_buf_type = CMD_OR;
    }
    else if (current == '&' && next == '&') {
        buf[j] = 0;
        j++;
        info->cmd_buf_type = CMD_AND;
    }
    else if (current == ';') {
        buf[j] = 0;
        info->cmd_buf_type = CMD_CHAIN;
    }
    else {
        return 0;
    }

    *p = j;
    return 1;
}

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
    size_t j = *p;

    if (info->cmd_buf_type == CMD_AND && info->status) {
        buf[i] = 0;
        j = len;
    }
    else if (info->cmd_buf_type == CMD_OR && !info->status) {
        buf[i] = 0;
        j = len;
    }

    *p = j;
}

int replace_alias(info_t *info)
{
    list_t *node = NULL;
    char *alias_value = NULL;

    for (int i = 0; i < 10; i++) {
        node = node_starts_with(info->alias, info->argv[0], '=');
        if (!node)
            return 0;

        alias_value = _strchr(node->str, '=');
        if (!alias_value)
            return 0;

        alias_value = _strdup(alias_value + 1);
        if (!alias_value)
            return 0;

        free(info->argv[0]);
        info->argv[0] = alias_value;
    }

    return 1;
}

int replace_vars(info_t *info)
{
    for (int i = 0; info->argv[i]; i++) {
        char *arg = info->argv[i];

        if (arg[0] != '$' || !arg[1])
            continue;

        if (!_strcmp(arg, "$?")) {
            replace_string(&info->argv[i], _strdup(convert_number(info->status, 10, 0)));
            continue;
        }

        if (!_strcmp(arg, "$$")) {
            replace_string(&info->argv[i], _strdup(convert_number(getpid(), 10, 0)));
            continue;
        }

        list_t *node = node_starts_with(info->env, &arg[1], '=');
        if (node) {
            replace_string(&info->argv[i], _strdup(_strchr(node->str, '=') + 1));
            continue;
        }

        replace_string(&info->argv[i], _strdup(""));
    }

    return 0;
}

int replace_string(char **old, char *new)
{
    free(*old);
    *old = new;
    return 1;
}
