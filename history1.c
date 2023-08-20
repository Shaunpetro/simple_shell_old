#include "shell.h"

/**
 * renumber_history - renumbers history of linked list after changes
 * @info: Structure containing possible arguments.
 *
 * Return: the new histcount
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int z = 0;

	while (node)
	{
		node->num = z++;
		node = node->next;
	}
	return (info->histcount = z);
}
