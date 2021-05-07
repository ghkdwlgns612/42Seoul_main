/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:55:23 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/05 21:57:41 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *ptr, size_t size)
{
	int i;
	unsigned char *startptr;

	startptr = (unsigned char *)ptr;
	i = 0;
	while (size--)
		startptr[i++] = 0;
}