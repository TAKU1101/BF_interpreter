#include "bfi.h"

static int	check_file(t_info *info)
{
	int		fd;
	char	*filename;

	filename = info->filename;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fputs(CANT_OPEN_FILE, stderr);
	}
	info->fd = fd;
	return (fd);
}

int			check_info(t_info *info)
{
	if (!info->filename && !info->code)
	{
		fputs(NO_INPUT_ERROR, stderr);
		return (1);
	}
	if (info->filename && check_file(info) == -1)
		return (1);
	return (0);
}
