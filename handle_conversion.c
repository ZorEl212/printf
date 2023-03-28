#include "main.h"


/**
 * conv_handler - selects the correct function to perform the operation.
 * @s: The format specifier passed to the function.
 * @index: The position of the format specifier in the format string.
 *
 * Return: A pointer to the corresponding function to perform the operation.
 */
int (*conv_handler(const char *s, int index))(va_list, char *, unsigned int)
{
	print_t pr[] = {
		{"s", handle_str}, {"c", handle_char}, {"%", handle_perc},
		{"d", handle_int}, {"i", handle_int}, { " d", handle_sint},
		{" i", handle_sint}, {"+d", handle_pint}, {"+i", handle_pint},
		{"#d", handle_int}, {"#i", handle_int}, {"+ i", handle_pint},
		{"+ d", handle_pint}, {" +i", handle_pint},
		{" +d", handle_pint}, {"b", handle_binary}, {"u", handle_uint},
		{" u", handle_uint}, {"#u", handle_uint}, {"+u", handle_uint}, 
		{"o", handle_oct}, {"x", handle_hex}, {"X", handle_upx},
		{"+o", handle_oct}, {"+x", handle_hex}, {"+X", handle_upx},
		{" o", handle_oct}, {" x", handle_hex}, {" X", handle_upx},
		{"#o", handle_noct}, {"#x", handle_nhex}, {"#X", handle_nupx},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].f);
}
