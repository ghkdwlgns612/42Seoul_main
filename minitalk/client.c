/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:35:59 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/08/04 18:46:54 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	change_bit(int server_pid, char code)
{
	int	mask;

	mask = 128;
	while (mask > 0)
	{
		if (code & mask)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_putstr_fd("SIGUSR1 Error\n", 1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_putstr_fd("SIGUSR2 Error\n", 1);
		}
		usleep(100);
		mask /= 2;
	}
}

void	send(pid_t pid, char *str)
{
	int	server_pid;
	int	i;

	server_pid = pid;
	i = 0;
	while (str[i])
		change_bit(server_pid, str[i++]);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
		ft_putstr_fd("Argument Error\n", 1);
	if (pid <= 0)
		ft_putstr_fd("PID Error\n", 1);
	send(pid, argv[2]);
	return (0);
}