#include "main.h"

/**
 * handle_str - helper function of printfto print strings
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */

int handle_str(va_list arguments, char *buf, unsigned int ibuf)
{
	char *s;
	size_t len;

	s = va_arg(arguments, char *);
	if (s == NULL)
	{
		len = sizeof("(null)") - 1;
		memcpy(buf + ibuf, "(null)", len);
		ibuf += len;
		return (6);
	}
	else
	{
		len = strlen(s);
		memcpy(buf + ibuf, s, len);
		ibuf += len;
	}
	return (len);
}
