/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:52:03 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:55:55 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			size;
	t_format	*inform;

	inform = (t_format*)malloc(sizeof(t_format));
	va_start(inform->ap, format);
	init_firstnode(inform, (char *)format);
	start_printf(inform);
	if (inform->spec == '0')
	{
		va_end(inform->ap);
		free(inform);
		return (-1);
	}
	va_end(inform->ap);
	size = inform->nums;
	free(inform);
	return (size);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(t_format *inform)
{
	int i;

	i = 0;
	if (inform->spec == 'c' && inform->num[0] == '\0')
	{
		while (i < inform->max_size)
		{
			write(1, &inform->result[i], 1);
			i++;
		}
		inform->nums += inform->max_size;
		return ;
	}
	while (inform->result[i] != 0)
	{
		write(1, &inform->result[i], 1);
		i++;
	}
	inform->nums += pf_strlen(inform->result);
}
