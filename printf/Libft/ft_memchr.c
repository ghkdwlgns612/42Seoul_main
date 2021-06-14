/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:10:59 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/07 15:14:32 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t num)
{
	unsigned char	*str_cp;
	size_t			i;

	i = 0;
	str_cp = (unsigned char *)str;
	while (i < num)
	{
		if (str_cp[i] == (unsigned char)c)
			return ((unsigned char *)&str_cp[i]);
		i++;
	}
	return (0);
}
