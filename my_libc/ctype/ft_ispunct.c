#include "libft.h"

int	ft_ispunct(int c)
{
	return (('!' <= c && c <= '/') || (':' <= c && c <= '@') || \
			('[' <= c && c <= '`') || ('{' <= c && c <= '}'));
}
