#include "utils.h"
#include <unistd.h>

void	init_printf(t_printf *main)
{
	main->len = 0;
	main->index = 0;
	main->total_len = 0;
	ft_bzero(main->buffer, BUFFER_SIZE);
}

void	flush_printf(t_printf *main)
{
	if (main->len > 0)
	{
		write(STDOUT_FILENO, main->buffer, main->len);
		main->total_len += main->len;
		main->len = 0;
		ft_bzero(main->buffer, BUFFER_SIZE);
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

void put_base(t_printf *main, unsigned long long num, const char *base)
{
	char buffer[MAX_BINARY + 1];
	int base_len;
	int i;

	i = 0;
	base_len = 0;
	ft_bzero(buffer, sizeof(buffer));
	while (base[base_len])
		base_len++;
	if (num == 0)
	{
		put_char(main, base[0]);
		return;
	}
	while (num > 0)
	{
		buffer[i++] = base[num % base_len];
		num /= base_len;
	}
	while (i > 0)
	{
		put_char(main, buffer[--i]);
	}
}
