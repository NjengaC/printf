#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * handle_u - handles conversion for %u
 * @num: unsigned int number to be converted
 *
 * Return: Pointer to formatted string
 */
char *handle_u(unsigned int num)
{
	char arr[32];
	int j, i = 0;
	char *result;

	do {
		arr[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	result = malloc(i + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (i > 0)
	{
		i--;
		result[j++] = arr[i];
	}
	result[j] = '\0';

	return (result);
}

/**
 * handle_octal - handles conversion for %o
 * @num: unsigned int number to be converted
 *
 * Return: Pointer to formatted string
 */
char *handle_octal(unsigned long int num)
{
	char arr[32];
	int remainder, j, i = 0;
	char *result;

	do {
		remainder = num % 8;
		arr[i++] = remainder + '0';
		num /= 8;
	} while (num > 0);

	result = malloc(i + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (i > 0)
	{
		i--;
		result[j++] = arr[i];
	}
	result[j] = '\0';
	return (result);
}
/**
 * handle_hexa - handles conversion for %x
 * @num: unsigned int number to be converted
 *
 * Return: Pointer to formatted string
 */
char *handle_hexa(unsigned long int num)
{
	char arr[32];
	int remainder, j, i = 0;
	char *result;

	do {
		remainder = num % 16;
		arr[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
		num /= 16;
	} while (num > 0);

	result = malloc(i + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (i > 0)
	{
		i--;
		result[j++] = arr[i];
	}
	result[j] = '\0';

	return (result);
}

/**
 * handle_HEXA - handles conversion for %X
 * @num: unsigned int number to be converted
 *
 * Return: Pointer to formatted string
 */
char *handle_HEXA(unsigned long int num)
{
	char arr[32];
	int remainder, j, i = 0;
	char *result;

	do {
		remainder = num % 16;
		arr[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
		num /= 16;
	} while (num > 0);

	result = malloc(i + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (i > 0)
	{
		i--;
		result[j++] = arr[i];
	}
	result[j] = '\0';

	return (result);
}
/**
 * handle_S - handle %S Non-printable characters
 * @input: input from the required argument
 * Return: a string after conversion according to required output
 */
char *handle_S(char *input)
{
	size_t len, j, i;
	char *result;
	unsigned char c;

	len = _strlen(input);
	result = malloc(len * 4 + 1);
	if (!result)
	{
		return (NULL);
	}

	j = 0;
	for (i = 0; i < len; i++)
	{
		c = input[i];
		if (c < 32 || c >= 127)
		{
			result[j++] = '\\';
			result[j++] = 'x';
			result[j++] = "0123456789ABCDEF"[c >> 4];
			result[j++] = "0123456789ABCDEF"[c & 0xF];
		}
		else
		{
			result[j++] = c;
		}
	}
	result[j] = '\0';
	return (result);
}
