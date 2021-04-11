#ifndef BFI_H
# define BFI_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "error_msg.h"

typedef struct s_info
{
	char		*filename;
	char		*code;
	int			buffer_size;
	char		*config_file;
}				t_info;

int				check_file(char *filename);
int				set_info(int argc, char *argv[], t_info *info);
void			init_info(t_info *info);

#endif
