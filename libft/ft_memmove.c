/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:34:34 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/07 14:10:17 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	i = 0;
	if (dest_cpy == src_cpy || num == 0)
		return (dest);
	if (dest_cpy < src_cpy)
		while (i < num)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	else
	{
		while (i < num)
		{
			dest_cpy[num - i - 1] = src_cpy[num - i - 1];
			i++;
		}
	}
	return (dest);
}
