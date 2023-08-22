#include "shell.h"

/**
 * get_environ - string array copy of the environ is returned
 * @info: Struct containing possible arguments.
 *    which is used to maintain constant func prototype.
 *
 * Return:0 Always
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove a environ variable
 * @info: Structure containing possible arguments.
 *    that are Used to maintain constant f prototype.
 *
 * Return: 1 on delete, otherwise 0
 *   @var: the string env var property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t z = 0;
	char *p;

	if (!node || !var)
	{
		return (0);
	}

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), z);
			z = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		z++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize new environ variable,
 *   or alter existing one
 * @info: info Struct containing possible arguments
 * @var: the string env var property
 * @value: the string env var value
 *
 * Return: 0 Always
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
