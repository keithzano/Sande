#include "shell.h"

/**
 * list_len - determines length of linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *head)
{
	size_t len = 0;
	for (; head; head = head->next)
		len++;
	return len;
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	size_t len = list_len(head);
	if (!len)
		return NULL;
	char **strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return NULL;
	for (size_t i = 0; head; i++, head = head->next)
	{
		size_t str_len = _strlen(head->str);
		char *str = malloc(sizeof(char) * (str_len + 1));
		if (!str)
		{
			for (size_t j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return NULL;
		}
		_strcpy(str, head->str);
		strs[i] = str;
	}
	strs[len] = NULL;
	return strs;
}

/**
 * print_list - prints all elements of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t len = 0;
	for (; head; head = head->next, len++)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
	}
	return len;
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @head: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *head, char *prefix, char c)
{
	for (; head; head = head->next)
	{
		if (starts_with(head->str, prefix) == head->str &&
			(c == -1 || head->str[_strlen(prefix)] == c))
			return head;
	}
	return NULL;
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	ssize_t index = 0;
	for (; head; head = head->next, index++)
	{
		if (head == node)
			return index;
	}
	return -1;
}
