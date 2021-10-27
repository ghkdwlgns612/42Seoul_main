#include "../so_long.h"

int	ft_mlx_pressed(int keycode, t_keys *keys)
{
	if (keycode == 53)
		exit(0);
	if ((keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		&& keys->check)
	{
		if (keycode == 13)
			keys->up = 1;
		if (keycode == 1)
			keys->down = 1;
		if (keycode == 0)
			keys->right = 1;
		if (keycode == 2)
			keys->left = 1;
		keys->check = 0;
	}
	return (0);
}

int	ft_mlx_released(int keycode, t_keys *keys)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
	{
		if (keycode == 13)
			keys->up = 0;
		if (keycode == 1)
			keys->down = 0;
		if (keycode == 0)
			keys->right = 0;
		if (keycode == 2)
			keys->left = 0;
		keys->check = 1;
	}
	return (0);
}

int	destroy_hook(int keycode, t_utilities *util)
{
	(void)keycode;
	(void)util;
	exit(0);

	return (0);
}