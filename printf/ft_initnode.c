/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:07:25 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/01 10:21:50 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_firstnode(t_format *t_node, char *format)
{
	int	i;

	i = 0;
	(t_node)->str = format;
	while (i < 4)
	{
		(t_node)->flag[i] = 0;
		i++;
	}
	(t_node)->spec = 0;
	i = 0;
	while (i < 22)
	{
		(t_node)->num[i] = 0;
		i++;
	}
	(t_node)->max_size = 0;
	(t_node)->wid = 0;
	(t_node)->prec = 0;
	(t_node)->size = 0;
	(t_node)->nums = 0;
	(t_node)->result = 0;
}

void	init_node(t_format *t_node)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(t_node)->flag[i] = 0;
		i++;
	}
	i = 0;
	while (i < 22)
	{
		(t_node)->num[i] = 0;
		i++;
	}
	(t_node)->max_size = 0;
	(t_node)->spec = 0;
	(t_node)->wid = 0;
	(t_node)->prec = 0;
	(t_node)->size = 0;
	free((t_node)->result);
	(t_node)->result = 0;
}
