#include "../include/so_long.h"


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

        if (!(ft_check_extension(argv[1],".ber")))
            ft_exit("Invalid file format");
        if (check_norms(util) == 1)
        {
            util.screen.win = mlx_new_window(util.screen.mlx, util.map.width * util.unitsize, util.map.height * 40, "so long");
            util.screen.img.ptr = mlx_new_image(util.screen.mlx, util.map.width * util.unitsize, util.unitsize * util.map.height);
            util.screen.img.addr = mlx_get_data_addr(util.screen.img.ptr, &util.screen.img.bpp, &util.screen.img.linelen, &util.screen.img.endian);

                        

        }
        close(fd);
    }
    else
    {
        ft_exit("Please, input the map!");
    }
    return (0);
}