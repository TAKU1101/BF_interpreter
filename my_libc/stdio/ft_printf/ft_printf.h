#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_format
{
	char		type;
	int			flag;
	int			width;
	int			precision;
}				t_format;

int				ft_printf(const char *fmt, ...);
t_format		change_format(char **fmt, va_list *ap);
int				put_format(t_format *fp, va_list *ap);
int				put_c(t_format *fp,va_list *ap);

void			put_num_sp(int n);

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strchr(const char *str, int c);

#endif
