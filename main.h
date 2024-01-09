#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFFER 1024

extern int buffer_track;
extern int printed_char;
extern char buffer[BUFFER];

int _printf(const char *format, ...);
int _putchar(char c);
void print_number(int n);
int _strlen(char *s);
void _puts(char *str);
void print_rev(char *s);
void rev_string(char *s);
void puts2(char *str);
void print_array(int *a, int n);
void fill_formated_buffer(const char *format, va_list args);
void fill_string_to_buffer(char *strn);
void fill_char_buffer(char c);
void fill_number(int numb);
void flush_buffer(void);
char *convert_binary(unsigned long int);
void handle_others(char specifier, va_list args);
char *handle_hexa(unsigned long int);
char *handle_HEXA(unsigned long int);
char *handle_octal(unsigned long int);
char *handle_u(unsigned int);
char *handle_S(char *input);
char *handle_pointer(void *ptr);
void handle_direct(char specifier, va_list args);

#endif
