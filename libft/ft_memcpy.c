/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:33:53 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/07 13:55:15 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (dest_cpy == src_cpy || num == 0)
		return (dest);
	while (i < num)
	{
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (dest);
}
