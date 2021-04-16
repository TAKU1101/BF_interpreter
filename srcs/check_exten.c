#include "bfi.h"

int	check_exten(char *filepath, char *exten)
{
	char	*exten_p;

	if ((exten_p = strrchr(filepath, '.')) == NULL)
		return (1);
	if (strcmp(&exten_p[1], exten))
		return (1);
	return (0);
}
