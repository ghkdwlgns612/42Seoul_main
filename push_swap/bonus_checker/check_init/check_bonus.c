/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:55:48 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 22:08:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../bonus.h"

int	ft_check(const char *str)
{
	int			i;
	long long	ret;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (!(i == 0 && str[i] == '-'))
				ft_error();
		}
		i++;
	}
	ret = ft_atoi(str);
	if (ret > 2147483647 || ret < -2147483648)
		ft_error();
	return ((int)ret);
}

void	ft_check_duplicate(t_node *node)
{
	t_node	*temp;
	int		value;

	while (node->next != NULL)
	{
		temp = node->next;
		value = node->value;
		while (temp != NULL)
		{
			if (temp->value == value)
				ft_error();
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		node = node->next;
	}
	while (node->prev != NULL)
		node = node->prev;
}
