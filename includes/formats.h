#ifndef FORMATS_H
# define FORMATS_H

#include "utils.h"

void	put_char(t_printf *main, char c);
void	put_string(t_printf *main, char *str);
void	put_percent(t_printf *main);

void	put_integer(t_printf *main, int number);
void	put_unsigned_integer(t_printf *main, unsigned int number);
void	put_hexadecimal(t_printf *main, unsigned int number, t_bool is_uppercase);

void	put_pointer(t_printf *main, unsigned long long address);

void	handle_unknown_format(t_printf *main, char format_char);

#endif