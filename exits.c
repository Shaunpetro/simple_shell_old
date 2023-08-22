#include "shell.h"

/**
 * *_strncpy - func to copy a string
 * @dest: the destination of str to be copied to
 * @src: the source str
 * @n: the amount of char's to be copied
 *
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int z, j;
	char *s = dest;

	z = 0;
	while (src[z] != '\0' && z < n - 1)
	{
		dest[z] = src[z];
		z++;
	}
	if (z < n)
	{
		j = z;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strncat - 2 strings concartinator
 * @dest: the 1st string
 * @src: the 2nd string
 * @n: max amount of bytes to be used
 *
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int z, j;
	char *s = dest;

	z = 0;
	j = 0;
	while (dest[z] != '\0')
		z++;
	while (src[j] != '\0' && j < n)
	{
		dest[z] = src[j];
		z++;
		j++;
	}
	if (j < n)
	{
		dest[z] = '\0';
	}
	return (s);
}

/**
 * *_strchr - locates a char in a string
 * @s: the string to parse
 * @c: the char to look for
 * Return: pointer (s) to the memory area
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
