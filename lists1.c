#include "shell.h"

/**
 * list_len - func to determine the length of linked list
 * @h: first node pointer
 *
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t z = 0;

	while (h)
	{
		h = h->next;
		z++;
	}
	return (z);
}

/**
 * list_to_strings - returns an array of strings of the atr list
 * @head: first node ptr
 *
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t z = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !z)
		return (NULL);
	strs = malloc(sizeof(char *) * (z + 1));
	if (!strs)
		return (NULL);
	for (z = 0; node; node = node->next, z++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < z; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[z] = str;
	}
	strs[z] = NULL;
	return (strs);
}

/**
 * print_list - print all elements of a linked list(list_t)
 * @h: 1st node pointer
 *
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t z = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		z++;
	}
	return (z);
}

/**
 * node_starts_with - func that returns a node string
 *    that starts with a prefix
 * @node: node pointer to list head
 * @prefix: prefix string to match
 * @c: the next char after prefix to match
 *
 * Return: match node, else null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
		{
			return (node);
		node = node->next;
		}
	}
	return (NULL);
}

/**
 * get_node_index - func tthat gets the index of a node
 * @head: head list pointer
 * @node: node pointer
 *
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t z = 0;

	while (head)
	{
		if (head == node)
			return (z);
		head = head->next;
		z++;
	}
	return (-1);
}
