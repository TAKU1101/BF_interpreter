#include "ft_printf.h"

void	put_num_sp(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
}
