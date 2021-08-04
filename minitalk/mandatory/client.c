#include "../utils/utils.h"

void	change_bit(int server_pid, char code)
{
	int	mask;

	mask = 128;
	while (mask > 0)
	{
		if (code & mask)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				{ft_putstr_fd("SIGUSR1 Error\n", 1);}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				{ft_putstr_fd("SIGUSR2 Error\n", 1);}
		}
		usleep(300);
		mask /= 2;
	}
}

int	send(pid_t pid, char *str)
{
	int server_pid = pid;
	int i = 0;

	while (str[i])
		change_bit(server_pid,str[i++]);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*mssg;
	int		i;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
		ft_putstr_fd("Argument Error\n", 1);
	if (pid <= 0)
		ft_putstr_fd("PID Error\n", 1);
	send(pid, argv[2]);
	return (0);
}