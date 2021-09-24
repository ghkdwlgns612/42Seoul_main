/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:47:16 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/18 15:29:25 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		s1_index;
	int		s2_index;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == 0)
		return (0);
	s1_index = 0;
	while (s1_index < s1_len)
	{
		str[s1_index] = s1[s1_index];
		s1_index++;
	}
	s2_index = 0;
	while (s2_index < s2_len)
		str[s1_index++] = s2[s2_index++];
	str[s1_index] = '\0';
	free(s1);
	return (str);
}

char		*ft_strdup(char *str)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	while (str[len])
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
