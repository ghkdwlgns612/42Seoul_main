/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:48:37 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 21:11:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push.h"

int	bubble_sort(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
		}
	}
	return (value[2]);
}

int	get_mid_value(t_node *node)
{	
	int	i;
	int	value[5];

	i = -1;
	while (++i < 5)
	{
		value[i] = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (bubble_sort(value));
}

int	get_max_value(int size, t_node *node)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

int	get_min_value(int size, t_node *node)
{
	int	min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

void	make_pivot(int r_num, t_inform *inform, t_stack *stack)
{
	long	max;
	long	min;

	max = get_max_value(r_num, stack->top);
	min = get_min_value(r_num, stack->top);
	inform->pivot_max = (min + max) / 2;
	inform->pivot_min = (inform->pivot_max + min) / 2;
}
