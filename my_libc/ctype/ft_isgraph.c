#include "libft.h"

int	ft_isgraph(int c)
{
	return (('\t' <= c && c <= '\r'));
}
