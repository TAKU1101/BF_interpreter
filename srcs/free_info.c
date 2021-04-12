#include "bfi.h"

static void	free_str(char *str)
{
	if (!str)
	{
		free(str);
		str = NULL;
	}
}

void	free_info(t_info *info)
{
	free_str(info->filename);
	free_str(info->code);
	free_str(info->config_file);
	free_str(info->code_char);
}