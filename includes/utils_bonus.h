#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

#include "utils.h"

typedef struct s_format
{
	t_bool	flag_minus;
	t_bool	flag_plus;
	t_bool	flag_space;
	t_bool	flag_zero;
	t_bool	flag_hash;

	int		width;
	int		precision;
	t_bool	precision_specified;
	char	specifier;

}	t_format;

#endif