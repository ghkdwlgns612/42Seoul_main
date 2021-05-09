/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:40:34 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 14:40:34 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putendl_fd(char *s, int fd)
{
    size_t     len;

    len = ft_strlen(s);
    if (s == 0 || fd < 0)
        return ;
    write(fd, s, len);
    write(fd, "\n", 1);
}