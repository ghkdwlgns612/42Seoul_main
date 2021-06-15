/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:53:46 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:53:54 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_c(t_format *inform)
{
	unsigned char	c;
	int				i;

	c = (unsigned char)va_arg(inform->ap, int);
	if (c == 0)
		c = '\0';
	inform->size = 1;
	judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size + 1);
	if (inform->flag[0] == 1)
		c_flag_minus(inform, c);
	else if (inform->flag[1] == 1)
		c_flag_zero(inform, c);
	else
		c_noflag(inform, c);
}
