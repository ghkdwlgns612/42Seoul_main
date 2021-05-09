/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:33:42 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 14:33:42 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    size_t     len;

    len = ft_strlen(s);
    if (s == 0 || fd < 0)
        return ;
    write(fd, s, len);
}