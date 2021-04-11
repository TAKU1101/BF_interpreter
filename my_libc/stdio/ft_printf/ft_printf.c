#include "ft_printf.h"

static int	no_format(const char **fmt)
{
	const char	*tmp;
	int			n;

	n = 0;
	tmp = *fmt;
	while (**fmt != '%' && **fmt != 0)
	{
		write(1, *fmt, 1);
		n++;
		(*fmt)++;
	}
	return (*fmt - tmp);
}

static int	is_format(const char **fmt, va_list *ap)
{
	int			n;
	t_format	ft;

	ft = change_format((char **)fmt, ap);
	// printf("%d %d %d %c", ft.flag, ft.width, ft.precision, ft.type);
	n = put_format(&ft, ap);
	// printf("n: %d\n", n);
	// printf("ft.flag: %d\n", ft.flag);
	// printf("ft.per : %d\n", ft.precision);
	// printf("ft.widt: %d\n", ft.width);
	// printf("ft.type: %c\n", ft.type);
	return (n);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, fmt);
	if (!*fmt)
		return (-1);
	n = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			n += no_format(&fmt);
		else
			n += is_format(&fmt, &ap);
	}
	va_end(ap);
	return (n);
}
