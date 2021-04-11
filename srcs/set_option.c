#include "bfi.h"

static void	put_help(void)
{
	ft_putendl_fd("usage: bfi [option] ... [-c cmd|file|-] ...", 1);
	ft_putendl_fd("Options and arguments", 1);
	ft_putendl_fd("-h      : Standard output of how to use bfi, the option you're currently using.", 1);
	ft_putendl_fd("-c      : Treat the string after the option as a code", 1);
	ft_putendl_fd("-b      : Specify the size of the buffer as a natural number, default is 30000.", 1);
	ft_putendl_fd("--config: You can specify the characters to be used in the code, and the buffer size.", 1);
	ft_putendl_fd("          ex.) +=$", 1);
	ft_putendl_fd("               >=%", 1);
	ft_putendl_fd("               buffer_size=57", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("The code consists of the following eight characters (default case)", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("The code consists of the following eight characters (default case)", 1);
	ft_putendl_fd("+: Increment the value pointed to by the pointer", 1);
	ft_putendl_fd("-: decrement of the value pointed to by the pointer", 1);
	ft_putendl_fd(">: Increment the pointer", 1);
	ft_putendl_fd("<: decrement the pointer", 1);
	ft_putendl_fd(".: output the value pointed to by the pointer to the standard output", 1);
	ft_putendl_fd(",: standard input for the value pointed to by the pointer", 1);
	ft_putendl_fd("[: move to ']' if the pointer points to a value of 0", 1);
	ft_putendl_fd("]: move to '[' if the pointer points to a non-zero value", 1);
}

int			set_info(int argc, char *argv[], t_info *info)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp("-h", argv[i]))
			put_help();
		else if (!ft_strcmp("-c", argv[i]))
			;
		else if (!ft_strcmp("-b", argv[i]))
			;
		else if (!ft_strcmp("-config", argv[i]))
			;
		i++;
	}
	(void)info;
	return (0);
}
