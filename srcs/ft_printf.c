#include "formats.h"
#include "unistd.h"

static void	printf_loop(const char *format, t_printf *main, va_list args);
static void	handle_format(char format_char, t_printf *main, va_list args);

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

static void	handle_format(char format_char, t_printf *main, va_list args)
{
	if (format_char == CHAR)
		put_char(main, (char) va_arg(args, int));
	else if (format_char == STRING)
		put_string(main, va_arg(args, char *));
	else if (format_char == INTEGER || format_char == INTEGER_UPPER)
		put_integer(main, va_arg(args, int));
	else if (format_char == UNSIGNED_INTEGER)
		put_unsigned_integer(main, va_arg(args, unsigned int));
	else if (format_char == HEXADECIMAL)
		put_hexadecimal(main, va_arg(args, unsigned int), FALSE);
	else if (format_char == HEXADECIMAL_UPPER)
		put_hexadecimal(main, va_arg(args, unsigned int), TRUE);
	else if (format_char == POINTER)
		put_pointer(main, va_arg(args, unsigned long long));
	else if (format_char == PERCENTAGE)
		put_percent(main);
	else
		handle_unknown_format(main, format_char);
}
