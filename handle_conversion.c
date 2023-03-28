#include "main.h"

{
	print_t pr[] = {
		{"c", handle_chr}, {"s", handle_str},
		{"i", handle_int}, {"d", handle_int},
		{"b", handle_bnary}, {"u", handle_uint},
		{"o", handle_oct}, {"x", handle_hex},
		{"X", handle_upx}, {"#o", handle_noct},
		{"#x", handle_nhex}, {"#X", handle_upx},
		{"#i", handle_int}, {"#d", handle_int},
		{"#u", handle_uint}, {"+i", handle_pint},
		{"+d", handle_pint}, {"+u", handle_uint},
		{"+o", handle_oct}, {"+x", handle_hex},
		{"+X", print_upx}, {" i", handle_sint},
		{" d", handle_sint}, {" u", handle_uint},
		{" o", handle_oct}, {" x", handle_hex},
		{" X", handle_upx}, {"R", print_rot},
		{"%", handle_pec},{" +i", handle_pint},
		{" +d", handle_pint}, {"+ i", handle_pint},
		{"+ d", handle_pint}, {" %", handle_perc},
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