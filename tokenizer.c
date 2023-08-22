#include "shell.h"

/**
 * **strtow - string splitter to words.
 *    Repeated delimiters to be ignored
 * @str: input string
 * @d: delimeter string
 *
 * Return: array of strings pointer,
 *    return or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int z, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (z = 0; str[z] != '\0'; z++)
		if (!is_delim(str[z], d) && (is_delim(str[z + 1], d) || !str[z + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (z = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[z], d))
			z++;
		k = 0;
		while (!is_delim(str[z + k], d) && str[z + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[z++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - string to words splitter
 * @str: the input string
 * @d: the delimeter
 * Return: array of strings pointer, or
 *   return NULL on failure
 */

char **strtow2(char *str, char d)
{
	int z, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (z = 0; str[z] != '\0'; z++)
		if ((str[z] != d && str[z + 1] == d) ||
				    (str[z] != d && !str[z + 1]) || str[z + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (z = 0, j = 0; j < numwords; j++)
	{
		while (str[z] == d && str[z] != d)
			z++;
		k = 0;
		while (str[z + k] != d && str[z + k] && str[z + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[z++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
