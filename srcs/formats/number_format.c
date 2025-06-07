#include "utils.h"

void put_integer(t_printf *main, int number)
{
	long long number_ll;

	number_ll = (long long) number;
	if (number_ll < 0)
	{
		put_char(main, '-');
		number_ll = -number_ll;
	}
	put_base(main, (unsigned long long)number_ll, BASE_DECIMAL);
}

void	put_pointer(t_printf *main, unsigned long long address)
{
	if (address == 0)
	{
		put_string(main, "(nil)");
		return ;
	}
	put_string(main, "0x");
	put_base(main, address, BASE_HEXADECIMAL);
}

void put_unsigned_integer(t_printf *main, unsigned int number)
{
	long long number_ll;

	number_ll = (long long) number;
	if (number_ll < 0)
	{
		put_char(main, '-');
		number_ll = -number_ll;
	}
	put_base(main, (unsigned long long)number, BASE_DECIMAL);
}

void put_hexadecimal(t_printf *main, unsigned int number, t_bool is_uppercase)
{
	const char *base;

	if (is_uppercase)
		base = BASE_HEXADECIMAL_UPPER;
	else
		base = BASE_HEXADECIMAL;
	put_base(main, (unsigned long long)number, base);
}
