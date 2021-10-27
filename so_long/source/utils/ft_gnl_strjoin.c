/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:46:26 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/27 16:46:35 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!(join = malloc(sizeof(char) *
					(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
			join[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			join[j++] = s2[i++];
	join[j] = '\0';
	free(s1);
	return (join);
}
