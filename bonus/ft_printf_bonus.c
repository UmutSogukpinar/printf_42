#include "utils_bonus.h"

static void	init_format(t_format *fmt);
static void	printf_loop(const char *format, t_printf *main, va_list args);
static void	handle_format(const char *format, t_printf *main, va_list args);

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
	while (format[main->index])
	{
		if (format[main->index] == '%')
		{
			(main->index)++;
			if (format[main->index] == '\0')
				break ;
			handle_format(format[main->index], main, args);
		}
		else
		{
			if (main->len < BUFFER_SIZE)
			{
				main->buffer[main->len++] = format[main->index];
			}
			else
			{
				flush_printf(main);
				main->buffer[main->len++] = format[main->index];
			}
		}
		(main->index)++;
	}
}

/*
	TODO:	1) implement parse_flags
	TODO:	2) implement parse_width
	TODO:	3) implement parse_precision
	TODO:	4) execute whole flags with proper specifier
*/
static void handle_format(const char *format, t_printf *main, va_list args)
{
    t_format fmt;

    init_format(&fmt);
    parse_flags(format, main, &fmt);
    parse_width(format, main, &fmt);
    parse_precision(format, main, &fmt);

    fmt.specifier = format[main->index];

}

static void	init_format(t_format *fmt)
{
	fmt->flag_hash = FALSE;
	fmt->flag_minus = FALSE;
	fmt->flag_plus = FALSE;
	fmt->flag_space = FALSE;
	fmt->flag_zero = FALSE;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->precision_specified = FALSE;
	fmt->specifier = '\0';
}
