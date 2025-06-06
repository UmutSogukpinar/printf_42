#ifndef UTILS_H
# define UTILS_H

# include "stdarg.h"
# include "stdlib.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define MAX_BINARY 64

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

// ============ Function Prototypes ============

void put_base(t_printf *main, unsigned long long num, const char *base);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	flush_printf(t_printf *main);

void	put_char(t_printf *main, char c);
void	put_string(t_printf *main, char *str);
void	put_percent(t_printf *main);

void	put_integer(t_printf *main, int number);
void	put_unsigned_integer(t_printf *main, unsigned int number);
void	put_hexadecimal(t_printf *main, unsigned int number, t_bool is_uppercase);

void	put_pointer(t_printf *main, unsigned long long address);

void	handle_unknown_format(t_printf *main, char format_char);

# endif