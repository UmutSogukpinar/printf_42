#include "utils.h"

void	put_percent(t_printf *main)
{
	put_char(main, PERCENTAGE);
}

void	put_char(t_printf *main, char c)
{
	if (main->len == BUFFER_SIZE)
		flush_printf(main);
	main->buffer[main->len++] = c;
}

void	put_string(t_printf *main, char *str)
{
	size_t i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (main->len == BUFFER_SIZE)
			flush_printf(main);
		main->buffer[main->len++] = str[i++];
	}
}

