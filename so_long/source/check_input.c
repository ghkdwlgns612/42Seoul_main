#include "../so_long.h"

void	ft_checkinput1(t_utilities *res)
{
	if (res->keys.up && !res->keys.left && !res->keys.down && !res->keys.right)
	{
		if (!(res->map.matrix[res->player.x - 1][res->player.y] == '1'))
		{
			res->player.steps++;
			if (res->map.matrix[res->player.x - 1][res->player.y] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.matrix[res->player.x][res->player.y] = 'E';
			else
				res->map.matrix[res->player.x][res->player.y] = '0';
			res->player.x--;
			if (res->map.matrix[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.matrix[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.matrix[res->player.x][res->player.y] = 'P';
			res->keys.up = 0;
		}
	}
}

void	ft_checkinput2(t_utilities *res)
{
	if (res->keys.right && !res->keys.left && !res->keys.down && !res->keys.up)
	{
		if (!(res->map.matrix[res->player.x][res->player.y - 1] == '1'))
		{
			res->player.steps++;
			if (res->map.matrix[res->player.x][res->player.y - 1] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.matrix[res->player.x][res->player.y] = 'E';
			else
				res->map.matrix[res->player.x][res->player.y] = '0';
			res->player.y--;
			if (res->map.matrix[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.matrix[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.matrix[res->player.x][res->player.y] = 'P';
			res->keys.right = 0;
		}
	}
}

void	ft_checkinput3(t_utilities *res)
{
	if (res->keys.down && !res->keys.left && !res->keys.up && !res->keys.right)
	{
		if (!(res->map.matrix[res->player.x + 1][res->player.y] == '1'))
		{
			res->player.steps++;
			if (res->map.matrix[res->player.x + 1][res->player.y] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.matrix[res->player.x][res->player.y] = 'E';
			else
				res->map.matrix[res->player.x][res->player.y] = '0';
			res->player.x++;
			if (res->map.matrix[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.matrix[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.matrix[res->player.x][res->player.y] = 'P';
			res->keys.down = 0;
		}
	}
}

void	ft_checkinput4(t_utilities *res)
{
	if (res->keys.left && !res->keys.up && !res->keys.down && !res->keys.right)
	{
		if (!(res->map.matrix[res->player.x][res->player.y + 1] == '1'))
		{
			res->player.steps++;
			if (res->map.matrix[res->player.x][res->player.y + 1] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.matrix[res->player.x][res->player.y] = 'E';
			else
				res->map.matrix[res->player.x][res->player.y] = '0';
			res->player.y++;
			if (res->map.matrix[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.matrix[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.matrix[res->player.x][res->player.y] = 'P';
			res->keys.left = 0;
		}
	}
}

