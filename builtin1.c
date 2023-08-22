#include "shell.h"

/**
 * _myhistory - displays the historyn by list,
 *    1 command per line,
 *       preceded with line numbers
 *       start at 0.
 * @info: Struct containing possible arguments.
 *
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct that has possible args
 * @str: the string alias
 *
 * Return: 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: info struct parameter containing possible arg's
 * @str: string alias
 *
 * Return: 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints the alias string
 * @node: node of the alias
 *
 * Return: 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitator of built in alias (man alias)
 * @info: info struct containing possible arguments.
 * Return: Always 0
 */

int _myalias(info_t *info)
{
	int z = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (z = 1; info->argv[z]; z++)
	{
		p = _strchr(info->argv[z], '=');
		if (p)
			set_alias(info, info->argv[z]);
		else
			print_alias(node_starts_with(info->alias, info->argv[z], '='));
	}
	return (0);
}
