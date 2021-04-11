#include "ft_printf.h"

static void	set_flags(char **fmt, t_format *fp)
{
	(*fmt)++;
	fp->flag = 1;
	if (**fmt == '-')
	{
		fp->flag = -1;
		(*fmt)++;
	}
	else if (**fmt == '0')
	{
		fp->flag = 0;
		(*fmt)++;
	}
}

static void	set_width(char **fmt, va_list *ap, t_format *fp)
{
	fp->width = 0;
	if (**fmt == '*')
	{
		fp->width = (int)va_arg(*ap, int);
		(*fmt)++;
	}
	else
	{
		fp->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

static void	set_precision(char **fmt, va_list *ap, t_format *fp)
{
	fp->precision = 0;
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			fp->precision = (int)va_arg(*ap, int);
			(*fmt)++;
		}
		else
		{
			fp->precision = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
	}
}

static int	set_type(char **fmt, t_format *fp)
{
	char	*tmp;

	fp->type = 0;
	if ((tmp = ft_strchr("cspdiuxX%", **fmt)))
	{
		(*fmt)++;
		fp->type = *tmp;
	}
	else
		return (1);
	return (0);
}

t_format	change_format(char **fmt, va_list *ap)
{
	t_format	fp;

	fp.flag = 1;
	set_flags(fmt, &fp);
	set_width(fmt, ap, &fp);
	set_precision(fmt, ap, &fp);
	set_type(fmt, &fp);
	return (fp);
}
