#include "utils/utils.h"
#include <stdio.h>

void		signal_handle(int a)
{
    printf("hello");
}

int			main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Not match argument number\n", STDERR_FILENO);
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd("Please input!!\n", STDERR_FILENO);
		return (1);
	}
    ft_putstr_fd("client pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
    ft_putchar_fd('\n', STDOUT_FILENO);
    signal(SIGINT, signal_handle);
    kill(ft_atoi(argv[1]), SIGINT);

}