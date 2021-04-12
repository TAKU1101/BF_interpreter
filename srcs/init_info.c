# include "bfi.h"

void	init_info(t_info *info)
{
	info->filename = NULL;
	info->code = NULL;
	info->buffer_size = 30000;
	info->config_file = NULL;
	info->code_char = strdup("+-><.,[]");
}