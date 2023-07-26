#include "so_long.h"

void	draw_player1(t_unit *info, int x, int y, int keycode)
{
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_w1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_a1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_S)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_s1,
			x * 50 + 10, y * 50 + 10);
	}
	else if (keycode == KEY_D)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img.player_d1,
			x * 50 + 10, y * 50 + 10);
	}
}

void	draw_player(t_unit *info, int keycode)
{
	draw_tile(info, info->player.x, info->player.y);
	if (info->movement >= 0)
		draw_player1(info, info->player.x, info->player.y, keycode);
}
