#include "stdio.h"
#include "includes/ft_printf.h"

int main()
{
	int len_mine = ft_printf("hello\n");
	int len = printf("hello\n");

	ft_printf("mine: %d, original: %d\n", len_mine, len);
	return (0);
}