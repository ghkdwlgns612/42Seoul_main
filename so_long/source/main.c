/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:44:57 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/28 14:34:11 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

void	util_screen_image(t_utilities *util)
{
	util->screen.win = mlx_new_window(util->screen.mlx,
			util->map.width * util->unitsize,
			util->map.height * 100, "so long");
	util->screen.img.ptr = mlx_new_image(util->screen.mlx,
			util->unitsize * util->map.width,
			util->unitsize * util->map.height);
	util->screen.img.addr = mlx_get_data_addr(util->screen.img.ptr,
			&util->screen.img.bpp,
			&util->screen.img.linelen, &util->screen.img.endian);
}

t_RowsCols	matrix_row_col(int fd)
{
	t_RowsCols	s;
	char		*line;
	int			row;
	int			col;
	int			ret;

	line = NULL;
	row = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		row++;
		free(line);
		col = ft_gnl_strlen(line);
		if (!ret)
			break ;
	}
	s.rows = row;
	s.cols = col;
	return (s);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_utilities	util;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		util = start(fd, argv[1]);
		if (!(ft_check_extension(argv[1], ".ber")))
			ft_exit("Invalid file format.");
		if (check_norms(util) == 1)
		{
			util_screen_image(&util);
			system("leaks so_long");
			mlx_hook(util.screen.win, 2, 0, ft_mlx_pressed, &(util.keys));
			mlx_hook(util.screen.win, 3, 0, ft_mlx_released, &(util.keys));
			mlx_hook(util.screen.win, 17, 0, destroy_hook, &util);
			mlx_loop_hook(util.screen.mlx, ft_render, &util);
			mlx_string_put(util.screen.mlx, util.screen.win,
				0, 0, 0xFFFFFF, ft_itoa(util.player.steps));
			mlx_loop(util.screen.mlx);
		}
		close(fd);
	}
	else
		ft_exit("Please, input the map!");
	return (0);
}
