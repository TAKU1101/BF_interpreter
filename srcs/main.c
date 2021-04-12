#include "bfi.h"

int main(int argc, char *argv[], char *envp[])
{
	t_info	info;

	init_info(&info);
	if (set_info(argc, argv, &info))
		return (1);
	if (check_info(&info))
		return (1);
	return (0);
//	check_file(argv[1]);
	(void)envp;
}
