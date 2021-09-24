/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:34:41 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/08/04 17:40:01 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s || fd < 0)
		return (-1);
	len = ft_strlen(s);
	len = write(fd, s, len);
	return (len);
}
