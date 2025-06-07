#ifndef UTILS_H
# define UTILS_H

// ======= Implemented Libraries =======

# include "stdarg.h"
# include "stdlib.h"

// ========= MACROS =========

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# define BASE_DECIMAL "0123456789"
# define BASE_HEXADECIMAL "0123456789abcdef"
# define BASE_HEXADECIMAL_UPPER "0123456789ABCDEF"

# define CHAR 'c'
# define STRING 's'
# define INTEGER 'd'
# define INTEGER_UPPER 'i'
# define UNSIGNED_INTEGER 'u'
# define HEXADECIMAL 'x'
# define HEXADECIMAL_UPPER 'X'
# define POINTER 'p'
# define PERCENTAGE '%'

# define MAX_BINARY 64

// ============ Enums ============

typedef enum e_bool
{
	FALSE_,
	TRUE_

}	t_bool;

// ============ Structs ============

typedef struct s_printf
{
	size_t	index;
	size_t	len;
	size_t	total_len;
	char	buffer[BUFFER_SIZE];

}	t_printf;

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

// ============ Function Prototypes ============

void	put_base(t_printf *main, unsigned long long num, const char *base);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	flush_printf(t_printf *main);
void	init_printf(t_printf *main);

# endif