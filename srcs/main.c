#include "bfi.h"

int main(int argc, char *argv[])
{
	t_info	info;

	init_info(&info);
	if (set_info(argc, argv, &info))
		return (1);
	if (check_info(&info))
		return (1);
	exec_code(&info);
	free_info(&info);
	return (0);
}
