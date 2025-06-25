#include "utils_bonus.h"

char *apply_precision(t_format *f, char *str, t_bool is_negative)
{
	int		len;
	int		pad;
	char	*res;
	int		i;

	len = ft_strlen(str) - ((int) is_negative);
	if (f->precision > len)
		pad = f->precision - len;
	else
		pad = 0;
	if (f->precision == 0 && str[0] == '0')
		return (ft_strdup(""));
	if (pad <= 0)
		return (ft_strdup(str));
	res = malloc(pad + ft_strlen(str) + 2);
	if (!res)
		exit(EXIT_FAILURE);					// ? Can I use exit??
	i = 0;
	if (is_negative)
		res[i++] = '-';
	memset(res + i, '0', pad);
	strcpy(res + i + pad, str + (int)is_negative);
	return (res);
}
