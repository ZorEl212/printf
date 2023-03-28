#include "main.h"

/**
 * handle_int - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int handle_int(va_list arguments, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int in, temp, i, div, isneg;

	input = va_arg(arguments, int);
	if (input == 0)
	{
		ibuf = check_buff(buf, '0', ibuf);
		return (1);
	}

	isneg = 0;
	if (input < 0)
	{
		in = input * -1;
		ibuf = check_buff(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		in = input;
	}

	temp = in;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = check_buff(buf, ((in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

/**
 * handle_pint - print integer with plus symbol
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int handle_pint(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = check_buff(buf, '-', ibuf);
	}
	else
	{
		int_in = int_input;
		ibuf = check_buff(buf, '+', ibuf);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = check_buff(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}

/**
 * handle_sint - prints int begining with space
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int handle_sint(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = check_buff(buf, '-', ibuf);
	}
	else
	{
		int_in = int_input;
		ibuf = check_buff(buf, ' ', ibuf);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = check_buff(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}
