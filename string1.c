#include "shell.h"

/**
 * _strcpy - func to copy a string
 * @dest: the destination
 * @src: source
 *
 * Return: ptr to desti
 */

char *_strcpy(char *dest, char *src)
{
	int z = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[z])
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = 0;
	return (dest);
}

/**
 * _strdup - func to duplicate a string
 * @str: the string to duplicate
 *
 * Return: ptr to the duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - input string to be printed
 * @str: the string to be printed
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int z = 0;

	if (!str)
		return;
	while (str[z] != '\0')
	{
		_putchar(str[z]);
		z++;
	}
}

/**
 * _putchar - writes the char c to standard
 *    output
 * @c: The char to print
 *
 * Return: On success 1. On error return neg 1
 *    and error no. is set appropriately.
 */

int _putchar(char c)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(1, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}
