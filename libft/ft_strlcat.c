/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:37:39 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/07 16:07:04 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (size == 0)
		return (s_len);
	while (src[i] != 0 && d_len + i < size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (d_len <= size)
	{
		dest[d_len + i] = 0;
		return (d_len + s_len);
	}
	return (size + s_len);
}
