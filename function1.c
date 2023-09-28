#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * _putchar - prints char c to stdout
 * @c: char to print
 *
 * Return: 1.
 * On error, -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * handle_pointer - converts the pointer's numerical value to hexadecimal,
 * and formats it with the "0x" prefix
 * @ptr: pointer from _printf Argemnts
 *
 * Return: a string with the output representation of the pointer
 */

char *handle_pointer(void *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	char arr[16];
	int i, j = 0;
	int remainder;
	char *result;

	do {
		remainder = address % 16;
		arr[j++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
		address /= 16;
	} while (address > 0);

	result = malloc(j + 3);
	if (!result)
	{
		return (NULL);
	}

	result[0] = '0';
	result[1] = 'x';
	for (i = j - 1; i >= 0; i--)
	{
		result[j - i + 1] = arr[i];
	}
	result[j + 2] = '\0';
	return (result);
}
/**
 * handle_direct - selects appropriately to handle astring or a character
 * @fmt: character specifier (either c or s)
 * @args: arguments as passed to _printf
 * Return: nothing
 */

void handle_direct(char fmt, va_list args)
{
	char n;
	char *str;

	if (fmt == 'c')
	{
		n = va_arg(args, int);
		fill_char_buffer(n);
	}
	else
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		fill_string_to_buffer(str);
	}
}
