#include "bfi.h"

static int	puts_help(void)
{
	fputs("usage: bfi [option] ... [-c cmd|file|-] ...\n", stdout);
	fputs("Options and arguments\n", stdout);
	fputs("-h      : Standard output of how to use bfi, the option you're currently using.\n", stdout);
	fputs("-c      : Treat the string after the option as a code\n", stdout);
	fputs("-b      : Specify the size of the buffer as a natural number, default is 30000.\n", stdout);
	fputs("\n", stdout);
	fputs("The code consists of the following eight characters (default case)\n", stdout);
	fputs("+: Increment the value pointed to by the pointer\n", stdout);
	fputs("-: decrement of the value pointed to by the pointer\n", stdout);
	fputs(">: Increment the pointer\n", stdout);
	fputs("<: decrement the pointer\n", stdout);
	fputs(".: output the value pointed to by the pointer to the standard output\n", stdout);
	fputs(",: standard input for the value pointed to by the pointer\n", stdout);
	fputs("[: move to ']' if the pointer points to a value of 0\n", stdout);
	fputs("]: move to '[' if the pointer points to a non-zero value\n", stdout);
	return (1);
}

static int	set_cmd(int i, char *argv[], t_info *info)
{
	if (!argv[i + 1])
	{
		fputs(C_OPTION_ERROR, stderr);
		return (1);
	}
	info->code = strdup(argv[i + 1]);
	return (0);
}

static int	puts_unkonown_option_error(char *option)
{
	fputs(UNKNOWN_OPTION, stderr);
	fputs(option, stderr);
	fputs("\n", stderr);
	return (1);
}

static int	set_buffer_size(int i, char *argv[], t_info *info)
{
	int n;

	if (!argv[i + 1])
	{
		fputs(C_OPTION_ERROR, stderr);
		return (1);
	}
	n = atoi(argv[i + 1]);
	if (n <= 0 || 100000 < n)
	{
		fputs(BUFFER_SIZE_ERROR, stderr);
		return (1);
	}
	info->buffer_size = n;
	return (0);
}
/*
static int	set_config(int i, char *argv[], t_info *info)
{
	FILE	*file;

	if (!argv[i + 1])
	{
		fputs(ONFIG_CANT_OPEN_FILE, stderr);
		return (1);
	}
	if ((file = fopen()))
}
*/
int			set_info(int argc, char *argv[], t_info *info)
{
	int i;
	int rtv;

	i = 1;
	rtv = 0;
	while (i < argc && !rtv)
	{
		if (!strcmp("-h", argv[i]))
		{
			rtv += puts_help();
			break;
		}
		else if (!strcmp("-b", argv[i]))
		{
			rtv += set_buffer_size(i, argv, info);
			i++;
		}
		else if (!strcmp("-c", argv[i]))
		{
			rtv += set_cmd(i, argv, info);
			break;
		}
/*		else if (!strcmp("--config", argv[i]))
		{
			rtv += set_config(i, argc, info);
		}
*/		else if (argv[i][0] == '-')
		{
			rtv += puts_unkonown_option_error(argv[i]);
			break;
		}
		else
		{
			info->filename = argv[i];
			break;
		}
		i++;
	}
	(void)info;
	return (!!rtv);
}
