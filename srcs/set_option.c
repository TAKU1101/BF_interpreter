#include "bfi.h"

int	set_info(int argc, char *argv[], t_info *info)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			(void)NULL;
		i++;
	}
	return (0);
}
