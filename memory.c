#include "shell.h"

/**
 * bfree - frees a pointer & zeros the address
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if freed,
 *    else return 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
