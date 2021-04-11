#include "libft.h"

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'));
}
