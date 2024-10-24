/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:05:53 by usogukpi          #+#    #+#             */
/*   Updated: 2024/10/23 21:27:11 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *content, ...);

void	ft_det_type(const char *content, va_list args, int *index, int *count);

int		ft_put_char(char c);
int     ft_str_len(char *str);
int		ft_print_char(va_list args);
int     ft_print_str(va_list args);

int     ft_put_number(long long num, char *base);
int		ft_print_int(va_list args, char *base);
int     ft_print_uns(va_list args, char *base);

int     ft_print_adress(va_list args, char *base);
#endif