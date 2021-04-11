#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (1)
	{
		if (*str1 != *str2 || !*str1 || !*str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
	}
	return (0);
}
