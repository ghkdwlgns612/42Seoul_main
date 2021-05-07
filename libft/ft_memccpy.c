/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:32:46 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/07 14:21:29 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int val, size_t size)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	unsigned char	val_cpy;
	size_t			i;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	val_cpy = (unsigned char)val;
	while (i < size)
	{
		if (src_cpy[i] == val_cpy)
		{
			dest_cpy[i] = val_cpy;
			return (&dest_cpy[i + 1]);
		}
		dest_cpy[i] = src_cpy[i];
		i++;
	}
	return (NULL);
}
