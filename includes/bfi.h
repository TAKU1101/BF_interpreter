#ifndef BFI_H
# define BFI_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "error_msg.h"

typedef struct s_info
{
	char		*filename;
	int			f_help;
}				t_info;

int				check_file(char *filename);

#endif
