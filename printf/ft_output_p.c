/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:54:00 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:54:06 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_flag_minus(t_format *inform, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		str++;
		str++;
		inform->result[i++] = '0';
		inform->result[i++] = 'x';
		while (inform->prec > inform->size + i - 3)
			inform->result[i++] = '0';
		while (*str != 0)
			inform->result[i++] = *str++;
		while (i < inform->max_size)
			inform->result[i++] = ' ';
	}
}

void	p_noflag(t_format *inform, char *str)
{
	int i;
	int j;

	i = 0;
	str++;
	str++;
	j = inform->max_size - inform->size;
	if (inform->prec > inform->size)
		j = inform->max_size - inform->prec - 2;
	while (j-- > 0)
		inform->result[i++] = ' ';
	inform->result[i++] = '0';
	inform->result[i++] = 'x';
	j = inform->prec - inform->size + 2;
	while (j-- > 0)
		inform->result[i++] = '0';
	while (*str != 0)
		inform->result[i++] = *str++;
}

void	ft_output_p(t_format *inform)
{
	unsigned long int	p;
	int					i;

	p = (unsigned long int)va_arg(inform->ap, void *);
	h_to_str(p, inform);
	p_exception_null(inform, p);
	judge_max(inform);
	i = inform->max_size;
	if ((inform->result = (char *)malloc(sizeof(char) * (i + 3))) == 0)
		return ;
	pf_bzero(inform->result, inform->max_size + 3);
	if (inform->flag[0] == 1)
		p_flag_minus(inform, inform->num);
	else
		p_noflag(inform, inform->num);
}

void	p_exception_null(t_format *inform, int num)
{
	if (inform->flag[2] == 1 && inform->prec == 0 && num == 0)
	{
		inform->num[2] = 0;
		inform->num[3] = 0;
		inform->size = 2;
	}
}
