#include "ft_printf.h"

int		put_format(t_format *fp, va_list *ap)
{
	if (fp->type == 'c')
		return (put_c(fp, ap));
	else if (fp->type == 's')
		return (0);
	else if (fp->type == 'p')
		return (0);
	else if (fp->type == 'd' || fp->type == 'i')
		return (0);
	else if (fp->type == 'u')
		return (0);
	else if (fp->type == 'x')
		return (0);
	else if (fp->type == 'X')
		return (0);
	else if (fp->type == '%')
		return (0);
	return (0);
}
