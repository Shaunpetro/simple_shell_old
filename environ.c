#include "shell.h"

/**
 * _myenv - current environment
 * @info: info Structure containing possible arg's,
 *    which maintains constant func prototype
 *
 * Return: Always 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the environment var value
 * @info: info struct containing posible arg's
 * @name: environment var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - init/set a new environment var/ modify an existing 1
 *    @info: Info Structure containing potential arg's.
 *
 *    Return: Always 0
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove a environment var
 * @info: Info Structure that contain possible arg's,
 * which is used to maintain
 *    constant function prototype.
 *
 * Return: Always 0
 */

int _myunsetenv(info_t *info)
{
	int z;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (z = 1; z <= info->argc; z++)
		_unsetenv(info, info->argv[z]);

	return (0);
}

/**
 * populate_env_list - populates the env linked list
 * @info: Info Structure containing possible arg's
 *
 *    Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t z;

	for (z = 0; environ[z]; z++)
		add_node_end(&node, environ[z], 0);
	info->env = node;
	return (0);
}
