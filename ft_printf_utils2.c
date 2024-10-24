/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:19:11 by usogukpi          #+#    #+#             */
/*   Updated: 2024/10/23 21:30:24 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdint.h>

int ft_put_number(long long num, char *base)
{
    int count;
    int base_len;

    base_len = ft_str_len(base);
    count = 0;
    if (num >= base_len)
        count += ft_put_number(num / base_len, base);
    ft_put_char(base[num % base_len]);
    return (count + 1);
}
int ft_print_int(va_list args, char *base)
{
    int count;
    int num;

    count = 0;
    num = va_arg(args, int);
    if (num == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (num < 0)
    {
        ft_put_char('-');
        num = -num;
        count++;
    }
    count += ft_put_number(num, base);
    return (count);
}
 
int ft_print_uns(va_list args, char *base)
{
    int             count;
    unsigned int    num;

    count = 0;
    num = va_arg(args, unsigned int);
    count += ft_put_number(num, base);
    return (count);
}
int ft_print_adress(va_list args, char *base)
{
    unsigned long long  num;
    int                 count;

    num = (unsigned long long) va_arg(args, int);
    write(1, "0x", 2);
    count = 0;
    count += 2;
    count += ft_put_number((long long) num, "0123456789abcdef");
    return (count);
}