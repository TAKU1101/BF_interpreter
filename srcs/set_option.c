#include "bfi.h"

static void	puts_help(void)
{
	fputs("usage: bfi [option] ... [-c cmd|file|-] ...\n", stdout);
	fputs("Options and arguments\n", stdout);
	fputs("-h      : Standard output of how to use bfi, the option you're currently using.\n", stdout);
	fputs("-c      : Treat the string after the option as a code\n", stdout);
	fputs("-b      : Specify the size of the buffer as a natural number, default is 30000.\n", stdout);
	fputs("--config: You can specify the characters to be used in the code, and the buffer size.\n", stdout);
	fputs("          ex.) +=$\n", stdout);
	fputs("               >=%\n", stdout);
	fputs("               buffer_size=57\n", stdout);
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

int			set_info(int argc, char *argv[], t_info *info)
{
	int i;
	int rtv;

	i = 1;
	rtv = 0;
	while (i < argc && !rtv)
	{
		if (!strcmp("-h", argv[i]))
			puts_help();
		else if (!strcmp("-b", argv[i]))
			(void)NULL;
		else if (!strcmp("--config", argv[i]))
			(void)NULL;
		else if (!strcmp("-c", argv[i]))
		{
			rtv += set_cmd(i, argv, info);
			break;
		}
		else if (argv[i][0] == '-')
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
