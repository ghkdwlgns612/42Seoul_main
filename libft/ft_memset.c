/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:35:06 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/07 14:20:55 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int				i;
	char			*start_ptr;
	unsigned char	data;

	start_ptr = (char *)ptr;
	data = (unsigned char)value;
	i = 0;
	while (num--)
		start_ptr[i++] = data;
	return (ptr);
}
