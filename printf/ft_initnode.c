/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:52:55 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 14:01:43 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_firstnode(t_format *inform, char *format)
{
	int	i;

	i = 0;
	(inform)->str = format;
	while (i < 4)
	{
		(inform)->flag[i] = 0;
		i++;
	}
	(inform)->spec = 0;
	i = 0;
	while (i < 22)
	{
		(inform)->num[i] = 0;
		i++;
	}
	(inform)->max_size = 0;
	(inform)->wid = 0;
	(inform)->prec = 0;
	(inform)->size = 0;
	(inform)->nums = 0;
	(inform)->result = 0;
}

void	init_node(t_format *inform)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(inform)->flag[i] = 0;
		i++;
	}
	i = 0;
	while (i < 22)
	{
		(inform)->num[i] = 0;
		i++;
	}
	(inform)->max_size = 0;
	(inform)->spec = 0;
	(inform)->wid = 0;
	(inform)->prec = 0;
	(inform)->size = 0;
	free((inform)->result);
	(inform)->result = 0;
}
