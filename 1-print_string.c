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
	size_t i;
	char null[] = "(null)";

	s = va_arg(arguments, char *);
	if (s == NULL)
	{
		for (i = 0; null[i]; i++)
			ibuf = check_buff(buf, null[i], ibuf);
		return (6);
	}
	for (i = 0; s[i]; i++)
		ibuf = check_buff(buf, s[i], ibuf);
	return (i);
}
