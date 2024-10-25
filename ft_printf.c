/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:05:56 by usogukpi          #+#    #+#             */
/*   Updated: 2024/10/23 21:29:39 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_det_type(format, args, &i, &count);
		else
			count += ft_put_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

void	ft_det_type(const char *format, va_list args, int *index, int *count)
{
	*index += 1;
	if (format[*index] == '%')
		*count += ft_put_char('%');
	else if (format[*index] == 'd')
		*count += ft_print_int(args, "0123456789");
	else if (format[*index] == 'i')
		*count += ft_print_int(args, "0123456789");
	else if (format[*index] == 'u')
		*count += ft_print_uns(args, "0123456789");
	else if (format[*index] == 'x')
		*count += ft_print_uns(args, "0123456789abcdef");
	else if (format[*index] == 'X')
		*count += ft_print_uns(args, "0123456789ABCDEF");
	else if (format[*index] == 'c')
		*count += ft_print_char(args);
	else if (format[*index] == 's')
		*count += ft_print_str(args);
	else if (format[*index] == 'p')
		*count += ft_print_adress(args, "0123456789abcdef");
}

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}
