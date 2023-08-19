#include "shell.h"

/**
 * _strlen - the length of a string to return
 * @s: the string to check the length
 *
 * Return: int length of string
 */

int _strlen(char *s)
{
	int z = 0;

	if (!s)
		return (0);

	while (*s++)
		z++;
	return (z);
}

/**
 * _strcmp - lexicogarphic comparison of two strngs.
 * @s1: the 1st strang
 * @s2: the second strang
 *
 * Return: neg if s1 < s2, positive if s1 > s2,
 *    0 if s1 equals s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);
	}
}

/**
 * starts_with - needle to check if it
 *    starts with haystack str
 * @haystack: string to search
 * @needle: the other substring to find
 *
 * Return: address of next char of haystack
 *   or return NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings func
 * @dest: the destination buffer
 * @src: the source buffer.
 *
 * Return: pointer to dest of buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
