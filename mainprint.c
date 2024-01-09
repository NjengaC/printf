#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
char buffer[BUFFER];
int buffer_track;
int printed_char = 0;
/**
 * fill_char_buffer - fills buffer with character
 * @c: character to fill
 *
 * Return: void
 */
void fill_char_buffer(char c)
{
	if (c == '\0')
	{
		buffer[buffer_track] = '\0';
		buffer_track++;
		return;
	}
	buffer[buffer_track] = c;

	if (buffer_track == BUFFER)
	{
		flush_buffer();
	}
	buffer_track++;
}
/**
 * fill_number - fills buffer with converted number
 * @numb: number to be filled
 * Return: void
 */
void fill_number(int numb)
{
	char arr[32];
	int temp = 1, i, length = 0;

	if (numb == 0)
	{
		fill_char_buffer('0');
		return;
	}
	if (numb < 0)
	{
		temp = 0;
		numb = (numb * -1);
	}

	while (numb != 0)
	{
		arr[length] = '0' + (numb % 10);
		numb /= 10;
		length++;
	}

	if (temp == 0)
	{
		arr[length] = '-';
		length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		fill_char_buffer(arr[i]);
	}
}
/**
 * fill_string_to_buffer - fills buffer with a  string
 * @strn: string
 *
 * Return: void
 */
void fill_string_to_buffer(char *strn)
{
	if (strn == NULL)
	{
		fill_string_to_buffer("(null)");
		return;
	}

	while (*strn != '\0')
	{
		fill_char_buffer(*strn);
		strn++;
	}
}
/**
 * handle_others - specifies helper functions to convert formated output
 * @specifier: character conversion specifier passed initially to _printf
 * @args: armuments as passed to the _printf variadic function
 *
 * Return: characters
 */
void handle_others(char specifier, va_list args)
{
	unsigned int unsig;
	unsigned long int binn;
	char *convert;
	void *pointer;

	if (specifier == '%')
	{
		fill_char_buffer('%');
	}
	else if (specifier == 'b')
	{
		binn = va_arg(args, unsigned long int);
		fill_string_to_buffer(convert_binary(binn));
	}
	else if (specifier == 'x')
	{
		binn = va_arg(args, unsigned long int);
		fill_string_to_buffer(handle_hexa(binn));
	}
	else if (specifier == 'X')
	{
		binn = va_arg(args, unsigned long int);
		fill_string_to_buffer(handle_HEXA(binn));
	}
	else if (specifier == 'o')
	{
		binn = va_arg(args, unsigned long int);
		fill_string_to_buffer(handle_octal(binn));
	}
	else if (specifier == 'u')
	{
		unsig = va_arg(args, unsigned int);
		fill_string_to_buffer(handle_u(unsig));
	}
	else if (specifier == 'S')
	{
		convert = va_arg(args, char*);
		fill_string_to_buffer(handle_S(convert));
	}
	else if (specifier == 'p')
	{
		pointer = va_arg(args, void *);
		fill_string_to_buffer(handle_pointer(pointer));
	}
	else
	{
		fill_char_buffer('%');
		fill_char_buffer(specifier);
	}
}
/**
 * _printf - prints filled buffer with charactes
 * @format: string that contains characters
 *
 * Return: characters
 */
int _printf(const char *format, ...){
	va_list args;
	char n;
	int num;
	/*int printed_char = 0;*/
	char *str;

	va_start(args, format);
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					n = va_arg(args, int);
					fill_char_buffer(n);
					break;
				case 's':
					str = va_arg(args, char *);
					fill_string_to_buffer(str);
					break;
				case 'd':
				case 'i':
					num  = va_arg(args, int);
					fill_number(num);
					break;
				default:
					handle_others(*format, args);
					format++;
					continue;
			}
		}
		else
			fill_char_buffer(*format);
	format++;
	}
	flush_buffer();
	va_end(args);
	return (printed_char);
}
