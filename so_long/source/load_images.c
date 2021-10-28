/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:44:34 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/28 15:32:32 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_startvalues(t_utilities *util)
{
	util->screen.mlx = mlx_init();
	util->exit.x = -1;
	util->exit.y = -1;
	util->player.x = -1;
	util->player.y = -1;
	util->player.items = 0;
	util->player.steps = 0;
	util->time = 0;
	util->state = 1;
	util->keys.check = 1;
}

void	ft_initplayer(t_utilities *util, int posx, int posy)
{
	if (!(util->player.x < 0 && util->player.y < 0))
		ft_exit("Multiple players are not permitted.");
	util->player.x = posx;
	util->player.y = posy;
}

void	ft_initexit(t_utilities *util, int posx, int posy)
{
	if (!(util->exit.x < 0 && util->exit.y < 0))
		ft_exit("Multiple exits are not permitted.");
	util->exit.x = posx;
	util->exit.y = posy;
}

void	ft_load_images(t_utilities *util)
{
	util->twall.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/wall1.xpm",
			&util->twall.width, &util->twall.height);
	util->twall.addr = mlx_get_data_addr(util->twall.ptr, &util->twall.bpp,
			&util->twall.linelen, &util->twall.endian);
	util->tplayer.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/hero.xpm",
			&util->tplayer.width, &util->tplayer.height);
	util->tplayer.addr = mlx_get_data_addr(util->tplayer.ptr,
			&util->tplayer.bpp, &util->tplayer.linelen, &util->tplayer.endian);
	util->tfood.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/burger.xpm",
			&util->tfood.width, &util->tfood.height);
	util->tfood.addr = mlx_get_data_addr(util->tfood.ptr, &util->tfood.bpp,
			&util->tfood.linelen, &util->tfood.endian);
	util->texit.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/exit.xpm",
			&util->texit.width, &util->texit.height);
	util->texit.addr = mlx_get_data_addr(util->texit.ptr, &util->texit.bpp,
			&util->texit.linelen, &util->texit.endian);
	util->tfloor.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/floor.xpm",
			&(util->tfloor.width), &(util->tfloor.height));
	util->tfloor.addr = mlx_get_data_addr(util->tfloor.ptr,
			&util->tfloor.bpp, &util->tfloor.linelen, &util->tfloor.endian);
}

void	ft_load_images_end(t_utilities *util)
{
	util->twin.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/win1.xpm",
			&(util->twin.width), &(util->twin.height));
	util->twin.addr = mlx_get_data_addr(util->twin.ptr,
			&util->twin.bpp, &util->twin.linelen, &util->twin.endian);
	util->tlose.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/lose.xpm",
			&(util->tlose.width), &(util->tlose.height));
	util->tlose.addr = mlx_get_data_addr(util->tlose.ptr,
			&util->tlose.bpp, &util->tlose.linelen, &util->tlose.endian);
}
