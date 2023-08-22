#include "shell.h"

/**
 * is_chain - test if current charecter
 *     in the current buffer is a chain delimeter
 * @info: the info parameter struct
 * @buf: the char buffer
 * @p: address of current position in bufffer
 *
 * Return: 1 if its a chain delimeter,
 *    else return 0
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*p = j;
	return (1);
}

/**
 * check_chain - checks if prog should
 *    continue chaining based on previous status
 * @info: the info parameter struct
 * @buf: the charecter buffer
 * @p: address of current position in buffer
 * @i: starting position in buffer
 * @len: length of buffer
 *
 * Return: Void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replace aliases in the tokenized string
 * @info: theinfo parameter struct
 *
 * Return: 1 if replaced when successful, 0 otherwise
 */

int replace_alias(info_t *info)
{
	int z;
	list_t *node;
	char *p;

	for (z = 0; z < 10; z++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		}
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
		{
			return (0);
		}
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replace the vars in tokenized str
 * @info: info parameter struct
 *
 * Return: 1 if replaced successfully, 0 otherwise
 */

int replace_vars(info_t *info)
{
	int z = 0;
	list_t *node;

	for (z = 0; info->argv[z]; z++)
	{
		if (info->argv[z][0] != '$' || !info->argv[z][1])
			continue;

		if (!_strcmp(info->argv[z], "$?"))
		{
			replace_string(&(info->argv[z]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[z], "$$"))
		{
			replace_string(&(info->argv[z]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[z][1], '=');
		if (node)
		{
			replace_string(&(info->argv[z]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[z], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replace a string
 * @old: address of  the old string
 * @new: new str
 *
 * Return: 1 if successfully replaced, 0 otherwise
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
