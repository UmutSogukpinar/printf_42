#include "utils.h"

void	handle_unknown_format(t_printf *main, char format_char)
{
	if (main->len == BUFFER_SIZE)
		flush_printf(main);
	main->buffer[main->len++] = '%';
	if (main->len == BUFFER_SIZE)
		flush_printf(main);
	main->buffer[main->len++] = format_char;
}
