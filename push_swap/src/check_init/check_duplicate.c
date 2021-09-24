/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:18:23 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 20:26:07 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

t_inform	*init_inform(void)
{
	t_inform	*inform;

	inform = (t_inform *)malloc(sizeof(t_inform));
	if (!inform)
		return (NULL);
	inform->pivot_max = 0;
	inform->pivot_min = 0;
	inform->ra = 0;
	inform->rb = 0;
	inform->pa = 0;
	inform->pb = 0;
	return (inform);
}

int	ft_check(const char *str)
{
	int			i;
	long long	ret;

	i = 0;
	ret = 0;
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
