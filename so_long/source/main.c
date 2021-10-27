/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:44:57 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/27 16:45:06 by jihuhwan         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    int fd;
    t_utilities util;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        util = start(fd, argv[1]);

        if (!(ft_check_extension(argv[1], ".ber"))) //평가지 확인필요.
            ft_exit("Invalid file format.");
        if (check_norms(util) == 1)
        {
            util.screen.win = mlx_new_window(util.screen.mlx, util.map.width * util.unitsize, util.map.height * 100, "so long"); //새 콘솔창을 띄웁니다.
            util.screen.img.ptr = mlx_new_image(util.screen.mlx,
                                                util.unitsize * util.map.width, util.unitsize * util.map.height);
            util.screen.img.addr = mlx_get_data_addr(util.screen.img.ptr,
                                                     &util.screen.img.bpp, &util.screen.img.linelen, &util.screen.img.endian);
            system("leaks so_long");
            mlx_hook(util.screen.win, 2, 0, ft_mlx_pressed, &(util.keys));
            mlx_hook(util.screen.win, 3, 0, ft_mlx_released, &(util.keys));
            mlx_hook(util.screen.win, 17, 0, destroy_hook, &util); //입력을 받으면 바로 실행.
            mlx_loop_hook(util.screen.mlx, ft_render, &util); //아무입력이 없는경우 무한루프로 렌더링을 해줍니다.
            mlx_string_put(util.screen.mlx, util.screen.win, 0, 0, 0xFFFFFF, ft_itoa(util.player.steps));
            mlx_loop(util.screen.mlx);
        }
        close(fd);
    }
    else
    {
        ft_exit("Please, input the map!");
    }
    return (0);
}
