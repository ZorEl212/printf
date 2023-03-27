#include "main.h"

/**
 * handle_perc - handle '%' when it is passed as identifier.
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int handle_perc(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	check_buff(buf, '%', i);

	return (1);
}
