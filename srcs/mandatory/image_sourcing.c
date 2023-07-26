#include "so_long.h"

void	load_images(t_unit *info, int img_width, int img_height)
{
	info->img.tile = mlx_xpm_file_to_image(info->mlx,
			"./tex/tile.xpm", &img_width, &img_height);
	info->img.wall = mlx_xpm_file_to_image(info->mlx,
			"./tex/wall.xpm", &img_width, &img_height);
	info->img.player_w1 = mlx_xpm_file_to_image(info->mlx,
			"./tex/Char_w.xpm", &img_width, &img_height);
	info->img.player_s1 = mlx_xpm_file_to_image(info->mlx,
			"./tex/Char_s.xpm", &img_width, &img_height);
	info->img.player_a1 = mlx_xpm_file_to_image(info->mlx,
			"./tex/Char_a.xpm", &img_width, &img_height);
	info->img.player_d1 = mlx_xpm_file_to_image(info->mlx,
			"./tex/Char_d.xpm", &img_width, &img_height);
	info->img.coin1 = mlx_xpm_file_to_image(info->mlx,
			"./tex/Chest.xpm", &img_width, &img_height);
	info->img.end = mlx_xpm_file_to_image(info->mlx,
			"./tex/exit.xpm", &img_width, &img_height);
}

void	check_images(t_unit *info)
{
	if (info->img.tile == NULL || info->img.wall == NULL
		||info->img.end == NULL || info->img.coin1 == NULL)
	{
		ft_printf("texture error");
		exit(0);
	}
	else if (info->img.player_a1 == NULL || info->img.player_w1 == NULL
		|| info->img.player_s1 == NULL || info->img.player_d1 == NULL )
	{
		ft_printf("player texture error");
		exit(0);
	}
}
