#include "bfi.h"

static char	*strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*p;
	char			*rp;

	len = strlen(s1) + strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	rp = p;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (rp);
}

static char	*wrap_read(int fd)
{
	int		rtv;
	char	buf[1000];
	char	*tmp;
	char	*res = strdup("");

	while ((rtv = read(fd, buf, 1000)) > 0)
	{
		buf[rtv] = 0;
		tmp = strjoin(res, buf);
		free(res);
		res = tmp;
	}
	return (res);
}

static char	*set_code(t_info *info)
{
	if (info->code)
		return (info->code);
	else
		return (wrap_read(info->fd));
	return (NULL);
}

static void	init_buffer(unsigned char buff[], int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		buff[i] = 0;
		i++;
	}
}

static int	exec_loop_start(int val, char *code, int *code_i)
{
	int	loop;

	loop = 0;
	if (!val)
	{
		(*code_i)++;
		while (code[*code_i] != ']' || loop > 0)
		{
			if (code[*code_i] == '[')
				loop++;
			else if (code[*code_i] == ']')
				loop--;
			(*code_i)++;
			if (!code[*code_i])
				return (1);
		}
	}
	return (0);
}

static int	exec_loop_end(int val, char *code, int *code_i)
{
	int	loop;

	loop = 0;
	if (val)
	{
		(*code_i)--;
		while (code[*code_i] != '[' || loop > 0)
		{
			if (code[*code_i] == ']')
				loop++;
			else if (code[*code_i] == '[')
				loop--;
			(*code_i)--;
			if (*code_i < 0)
				return (1);
		}
	}
	return (0);
}

void		exec_code(t_info *info)
{
	char			*code;
	unsigned char	buffer[info->buffer_size];
	int				code_i;
	int				buff_i;

	code_i = 0;
	buff_i = 0;
	init_buffer(buffer, info->buffer_size);
	code = set_code(info);
	while (code[code_i])
	{
		if (code[code_i] == '+')
			buffer[buff_i]++;
		else if (code[code_i] == '-')
			buffer[buff_i]--;
		else if (code[code_i] == '>')
			buff_i++;
		else if (code[code_i] == '<')
			buff_i--;
		else if (code[code_i] == '.')
			putchar(buffer[buff_i]);
		else if (code[code_i] == ',')
			buffer[buff_i] = getchar();
		else if (code[code_i] == '[')
			exec_loop_start(buffer[buff_i], code, &code_i);
		else if (code[code_i] == ']')
			exec_loop_end(buffer[buff_i], code, &code_i);
		code_i++;
	}
}
