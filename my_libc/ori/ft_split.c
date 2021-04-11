#include "libft.h"

static char	**set_point_malloc(char const *str, char c)
{
	int		i;
	int		count;
	char	**p;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (!(str[i] == c) && ((str[i + 1] == c) || (str[i + 1] == '\0')))
			count++;
	}
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (0);
	p[count] = 0;
	return (p);
}

static char	**set_malloc(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**p;

	p = set_point_malloc(str, c);
	if (!p)
		return (0);
	i = -1;
	j = -1;
	k = 0;
	while (str[++i])
	{
		if (str[i] == c && !(str[i + 1] == c))
			j = i;
		if (!(str[i] == c) && ((str[i + 1] == c)\
			|| (str[i + 1] == '\0')))
		{
			p[k++] = (char *)malloc(sizeof(char *) * (i - j + 1));
			if (!p[k])
				return (0);
			p[k - 1][i - j] = '\0';
		}
	}
	return (p);
}

char	**ft_split(char const *str, char c)
{
	char	**p;
	int		i;
	int		j;
	int		k;

	if (!(p = set_malloc(str, c)))
		return (0);
	i = -1;
	j = 0;
	if (str[0] == c)
		j = -1;
	k = 0;
	while (str[++i])
	{
		if (!(str[i] == c))
			p[j][k++] = str[i];
		if (str[i] == c && !(str[i + 1] == c))
		{
			(j != -1) ? p[j][k] = '\0' : 0;
			j++;
			k = 0;
		}
	}
	return (p);
}
