#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: count of printed characters
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	_putchar(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = conv_handler(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					check_buff(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += count_chars(format, i + 1);
				}
			} i++;
		}
		else
			check_buff(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	_putchar(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
}
