#include "bfi.h"

int	check_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fputs(CANT_OPEN_FILE, stderr);
	}
	return (fd);
}
