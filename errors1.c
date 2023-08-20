#include "shell.h"

/**
 * _erratoi - converts a string to an int
 * @s: the string to convert
 *
 * Return: 0 if no numbers in string converted number
 *    otherwise -1 on error
 */

int _erratoi(char *s)
{
	int z = 0;
	unsigned long int result = 0;

	if (*s == '+')
	{
		s++;
	}
	for (z = 0;  s[z] != '\0'; z++)
	{
		if (s[z] >= '0' && s[z] <= '9')
		{
			result *= 10;
			result += (s[z] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - func that prints an error message
 * @info: the parameter & return info struct
 * @estr: specific error type string
 *
 * Return: 0 if there are no numbers in str are
 *    converted number
 *    otherwise -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that prints a
 *    decimal (integer) a base 10 num
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int z, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (z = 1000000000; z > 1; z /= 10)
	{
		if (_abs_ / z)
		{
			__putchar('0' + current / z);
			count++;
		}
		current %= z;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - func to convert num
 * @num: number
 * @base: the base
 * @flags: te argument flags
 *
 * Return: string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * remove_comments - func that replaces first
 *     instance of comments / '#' with '\0'
 * @buf: address of the string
 *
 * Return: Always 0;
 */

void remove_comments(char *buf)
{
	int z;

	for (z = 0; buf[z] != '\0'; z++)
		if (buf[z] == '#' && (!z || buf[z - 1] == ' '))
		{
			buf[z] = '\0';
			break;
		}
}
