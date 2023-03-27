#ifndef _MAIN_H_
#define _MAIN_H_

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int handle_str(va_list arguments, char *buf, unsigned int ibuf);
int (*conv_handler(const char *s, int index))(va_list, char *, unsigned int);
int count_chars(const char *s, int index);
unsigned int check_buff(char *buf, char c, unsigned int ibuf);
int _putchar(char *buf, unsigned int nbuf);
int handle_char(va_list arguments, char *buf, unsigned int ibuf);

#endif
