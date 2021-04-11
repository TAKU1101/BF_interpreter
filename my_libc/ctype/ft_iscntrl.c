#include "libft.h"

int	ft_iscntrl(int c)
{
	return (!ft_isprint(c));
}
