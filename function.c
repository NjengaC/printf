#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * _memset - fill  memory with a  value
 * @s: address of memory to be filled
 * @b: value
 * @n: number of bytes to be changed
 *
 * Return: changed array with new value for n bytes
 */
void _memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
}

/**
 * _strlen - prints the length of a string
 * @s: set of string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}

/**
 * convert_binary - prints binary equivalent of a decimal number
 * @n: number to print in binary
 * Return: a string of binary characters
 */
char *convert_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;
	char *string;

	string = malloc(64 + 1);
	if (string == NULL)
		return (NULL);

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			string[count] = '1';
			count++;
		}
		else if (count)
		{
			string[count] = '0';
			count++;
		}
	}
	if (!count)
	{
		string[count] = '0';
		count++;
	}
	string[count] = '\0';
	return (string);
}
/**
 *  _puts - prints a string, followed by a new line, to stdout
 *   @str: string
 *
 *   Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
}
/**
 * flush_buffer - writes out to stdout when conditions are met
 * Return: nothing
 */
void flush_buffer(void)
{
	if (buffer == NULL)
		return;
	_puts(buffer);
	_memset(buffer, 0, sizeof(buffer));
	printed_char = printed_char + buffer_track;
	buffer_track = 0;
}

