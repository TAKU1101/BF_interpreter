#include "ft_printf.h"

static void	put_arg_c(va_list *ap)
{
	char cp;

	cp = (char)va_arg(*ap, int);
	write(1, &cp, 1);
}

int			put_c(t_format *fp, va_list *ap)
{
	if (fp->precision != 0 || fp->flag == 0)
		return (0);
	if (fp->flag == -1 || (fp->width <= 1))
		put_arg_c(ap);
	if (fp->width > 1)
	{
		put_num_sp(fp->width - 1);
		if (fp->flag == 1)
			put_arg_c(ap);
	}
	return (fp->width ? fp->width : 1);
}
