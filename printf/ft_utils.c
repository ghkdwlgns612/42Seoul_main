/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:52:38 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:52:45 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void			pf_bzero(void *ptr, size_t size)
{
	int				i;
	unsigned char	*startptr;

	startptr = (unsigned char *)ptr;
	i = 0;
	while (size--)
	{
		startptr[i] = 0;
		i++;
	}
}

void			do_itoa(unsigned int tmp, t_format *inform, int len)
{
	while (tmp > 0)
	{
		inform->num[len--] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
}

long long		check_size(long long n)
{
	long long		i;

	i = 0;
	if (n < 0)
		n = n * -1;
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
