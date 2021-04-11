#include "bfi.h"

int	check_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(CANT_OPEN_FILE, 2);
	}
	return (fd);
}
