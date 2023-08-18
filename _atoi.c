#include "shell.h"

/**
 * interactive - check if shell is interactive mode
 *    return true
 * @info: struct address
 *
 * Return: 1 if shell interactive mode, else 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if char is delimeter
 * @c: is the char to check
 * @delim: the delimeter str
 *
 * Return: true is 1, 0 is false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - for checking if alphabetic character
 * @c: is the character to input
 * Return: 1 if c is alphabetic or else 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi - convert string to an integer.
 * @s: the string to convert
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int z, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (z = 0; s[z] != '\0' && flag != 2; z++)
	{
		if (s[z] == '-')
			sign *= -1;

		if (s[z] >= '0' && s[z] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[z] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
