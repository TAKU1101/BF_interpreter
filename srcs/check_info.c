#include "bfi.h"

static int	check_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fputs(CANT_OPEN_FILE, stderr);
	}
	return (fd);
}

int			check_info(t_info *info)
{
	if (!info->filename && !info->code)
	{
		fputs(NO_INPUT_ERROR, stderr);
		return (1);
	}
	if (info->filename && check_file(info->filename))
		return (1);
	return (0);
}
