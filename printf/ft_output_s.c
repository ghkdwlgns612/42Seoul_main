/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:52:35 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 00:54:57 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_null(t_format *t_node, char **str)
{
	t_node->size = 6;
	*str = "(null)";
}

void	ft_output_s(t_format *t_node)
{
	char	*str;
	int		i;

	str = va_arg(t_node->ap, char *);
	t_node->size = pf_strlen(str);
	if (t_node->size == 0 && str == NULL)
		check_null(t_node, &str);
	judge_max(t_node);
	i = t_node->max_size;
	if ((t_node->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(t_node->result, t_node->max_size + 1);
	if (t_node->flag[0] == 1)
		s_flag_minus(t_node, str);
	else if (t_node->flag[1] == 1)
		s_flag_zero(t_node, str);
	else
		s_noflag(t_node, str);
}
