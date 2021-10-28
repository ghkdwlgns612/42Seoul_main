/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:44:34 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/28 12:59:17 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_startvalues(t_utilities *util)
{
  util->screen.mlx = mlx_init(); //소프트웨어와 디스플레이를 연결.
  util->exit.x = -1;
  util->exit.y = -1;
  util->player.x = -1;
  util->player.y = -1;
  util->player.items = 0;
  util->player.steps = 0;
  util->time = 0;
  util->state = 1; //게임의 상태(시작인지 끝났는지)
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
//mlx_xpm함수로 파일 디스크럽터를 생성해 그것을 이미지 포인터로 저장해놓고 get_addr로 색깔, 선의 크기, 엔디안을 저장합니다.
void ft_load_images(t_utilities *util)
{
  util->twall.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/wall1.xpm",
    &util->twall.width, &util->twall.height);
  util->twall.addr = mlx_get_data_addr(util->twall.ptr, &util->twall.bpp,
    &util->twall.linelen, &util->twall.endian);
  util->tplayer.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/hero.xpm",
    &util->tplayer.width, &util->tplayer.height);
  util->tplayer.addr = mlx_get_data_addr(util->tplayer.ptr, &util->tplayer.bpp,
    &util->tplayer.linelen, &util->tplayer.endian);
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
  util->twin.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/win1.xpm",
			&(util->twin.width), &(util->twin.height));
	util->twin.addr = mlx_get_data_addr(util->twin.ptr,
			&util->twin.bpp, &util->twin.linelen, &util->twin.endian);
  util->tlose.ptr = mlx_xpm_file_to_image(util->screen.mlx, "img/lose.xpm",
			&(util->tlose.width), &(util->tlose.height));
	util->tlose.addr = mlx_get_data_addr(util->tlose.ptr,
			&util->tlose.bpp, &util->tlose.linelen, &util->tlose.endian);  
}
//img/en에있는 적이미지 4개를 생성합니다.
void    ft_load_images1(t_utilities *res)
{
    char    *temp;
    char    *frame;
    char    *xpm;

    res->tenemy = malloc(4 * sizeof(t_img));
    res->i = 0;
    while (res->i < 4)
    {
        temp = ft_itoa(res->i);
        frame = ft_strjoin("img/en/", temp);
        xpm = ft_strjoin(frame, ".xpm");
        res->tenemy[res->i].ptr = mlx_xpm_file_to_image(res->screen.mlx, xpm,
                &(res->tenemy[res->i].width), &(res->tenemy[res->i].height));
        if (!(res->tenemy[res->i].ptr))
            ft_exit("Failed to allocate memory for a fire frame.");
        res->tenemy[res->i].addr = mlx_get_data_addr(res->tenemy[res->i].ptr,
                &res->tenemy[res->i].bpp, &res->tenemy[res->i].linelen,
                &res->tenemy[res->i].endian);
        free(xpm);
        free(frame);
        free(temp);
        res->i++;
    }
}

t_utilities start(int fd, char *argv)
{
  t_utilities util;
  t_RowsCols result;
  result = matrix_row_col(fd);
  
  util.map.height = result.rows;
  util.map.width = result.cols;
  util.unitsize = 100; //맵 중 하나의 image크기?
  ft_startvalues(&util);
  util.map.matrix = create_matrix(argv, fd, util.map.height, util.map.width);

  ft_setmatrixcharacters(&util);
  ft_load_images(&util);
  ft_load_images1(&util);
  return util;
}
