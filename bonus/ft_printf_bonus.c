#include "utils.h"

int	ft_printf(const char *format, ...)
{
	t_printf	main;
	va_list		args;

	if (!format)
		return (0);
	init_printf(&main);	
	va_start(args, format);
	printf_loop(format, &main, args);
	va_end(args);
	flush_printf(&main);
	return (main.total_len);
}

static void	printf_loop(const char *format, t_printf *main, va_list args)
{

}
