#ifndef BFI_H
# define BFI_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "error_msg.h"

/*
** code_char def "+-><.,[]"
*/

typedef struct s_info
{
	char		*filename;
	int			fd;
	char		*code;
	int			buffer_size;
	char		*config_file;
	char		*code_char;
}				t_info;

int				check_info(t_info *info);
int				set_info(int argc, char *argv[], t_info *info);
void			init_info(t_info *info);
void			free_info(t_info *info);
void			exec_code(t_info *info);
int				check_exten(char *filepath, char *exten);

#endif
