#include "libft.h"

static int	num_len(const char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(*(str++)))
	{
		i++;
	}
	return (i);
}

static	int	detection_overflow(const char *str, char ov[])
{
	int	len;

	len = num_len(str);
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	if (ft_strncmp(ov, str, 10) >= 0)
		return (0);
	return (1);
}

int			ft_isintoverflow(const char *str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (sign < 0 && detection_overflow(str, "2147483648"))
		return (1);
	else if (sign >= 0 && detection_overflow(str, "2147483647"))
		return (1);
    return (0);
}