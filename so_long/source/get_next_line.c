/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:44:07 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/27 16:44:13 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*the_line(char *tmp)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = 0;
	while (tmp && tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (!(line = (char *)malloc(i + 1)))
		return (NULL);
	while (j < i)
	{
		line[j] = tmp[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*leftover(char *tmp)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp && tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	if (!(ptr = (char *)malloc(ft_gnl_strlen(tmp) - i + 1)))
		return (NULL);
	i++;
	while (tmp[i])
		ptr[j++] = tmp[i++];
	ptr[j] = '\0';
	free(tmp);
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	char		*buf;
	static char *tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	r = 1;
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = ft_gnl_strjoin(tmp, buf);
		if (ft_gnl_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	*line = the_line(tmp);
	tmp = leftover(tmp);
	if (r < 0)
		return (-1);
	if (r == 0 && !tmp)
		return (0);
	return (1);
}
