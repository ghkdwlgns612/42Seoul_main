/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:54:48 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/15 11:54:55 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		g_hex_s[17] = "0123456789abcdef";
char		g_hex_b[17] = "0123456789ABCDEF";

void	d_to_str(t_format *inform, int n)
{
	int				len;
	unsigned int	tmp;

	if (n == 0)
	{
		inform->num[0] = '0';
		inform->num[1] = 0;
		inform->size = 1;
		return ;
	}
	len = check_size(n);
	if (n < 0)
	{
		tmp = n * -1;
		len++;
		inform->num[0] = '-';
	}
	else
		tmp = n;
	inform->size = len;
	inform->num[len] = 0;
	len--;
	do_itoa(tmp, inform, len);
}

void	u_to_str(t_format *inform, unsigned int n)
{
	int				len;
	unsigned int	tmp;

	if (n == 0)
	{
		inform->num[0] = '0';
		inform->num[1] = 0;
		inform->size = 1;
		return ;
	}
	len = check_size(n);
	tmp = n;
	inform->size = len;
	inform->num[len] = 0;
	len--;
	do_itoa(tmp, inform, len);
}

void	h_to_str(long long addr, t_format *inform)
{
	long long	temp;
	int			len;

	len = 0;
	temp = addr;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	len = len == 0 ? 3 : len + 2;
	inform->size = len;
	addr = temp;
	while (addr != 0)
	{
		inform->num[--len] = g_hex_s[addr % 16];
		addr /= 16;
	}
	inform->num[0] = '0';
	inform->num[1] = 'x';
	inform->num[2] = temp == 0 ? '0' : inform->num[2];
}

void	sx_to_str(t_format *inform, unsigned int addr)
{
	long long	temp;
	int			len;

	if (addr == 0)
	{
		inform->num[0] = '0';
		inform->size = 1;
		return ;
	}
	len = 0;
	temp = addr;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	len = len == 0 ? 0 : len;
	inform->size = len;
	addr = temp;
	while (addr != 0)
	{
		inform->num[--len] = g_hex_s[addr % 16];
		addr /= 16;
	}
}

void	bx_to_str(t_format *inform, unsigned int addr)
{
	long long	temp;
	int			len;

	if (addr == 0)
	{
		inform->num[0] = '0';
		inform->size = 1;
		return ;
	}
	len = 0;
	temp = addr;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	len = len == 0 ? 0 : len;
	inform->size = len;
	addr = temp;
	while (addr != 0)
	{
		inform->num[--len] = g_hex_b[addr % 16];
		addr /= 16;
	}
}
