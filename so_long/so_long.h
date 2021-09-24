#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 1

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
// #include <mlx.h>
#include <math.h>
#include <time.h>

typedef struct s_keys
{
    int     up;
    int     down;
    int     right;
    int     left;
    int     check;
}           t_keys;

typedef struct s_map
{
    int     width;
    int     height;
    char    **matrix;
}           t_map;

typedef struct s_img
{
    void	    *ptr;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
	int			width;
	int			height;
}               t_img;

typedef struct s_window
{
    void        *mlx;
    void        *win;
    t_img       img;
}               t_window;

typedef struct s_player
{
    int         x;
    int         y;
    int         items;
    int         goal;
    int         steps;
}               t_player;

typedef struct s_size
{
    int     row_size;
    int     col_size;
}               t_size;

typedef struct s_unit
{
    int         i;
    int         j;
    int         x;
    int         y;
    int			texx;
	int			texy;
    int			unitsize;
    int		    state; //game state(finished or not)
    double      time;
    int         frame;
    t_img		sprite;
    t_keys      keys;
    t_player    player;
    t_window    window;
    t_map       map;
    t_img		tfloor;
    t_img       tplayer;
    t_img       twall;
    t_img       tfood;
    t_img       texit;
    t_img       twin;
    t_img       tlose;
    t_img       *tenemy;
}               t_unit;

int	    ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *save, char *buff);
int     get_next_line(int fd, char **line);

#endif