#include "so_long.h"

void	move_player(t_unit *info, int keycode)
{
	if (check_end(keycode, info))
	{
		ft_printf("Chaaa_Ching 💰💰💰\n");
		exit(0);
	}
	if (check_coin(keycode, info))
		(info->coins)--;
	if (!(check_wall(keycode, info)))
	{
		draw_tile(info, info->player.x, info->player.y);
		info->map[info->player.y][info->player.x] = '0';
		if (keycode == KEY_W)
			info->player.y -= 1;
		else if (keycode == KEY_A)
			info->player.x -= 1;
		else if (keycode == KEY_S)
			info->player.y += 1;
		else if (keycode == KEY_D)
			info->player.x += 1;
		info->map[info->player.y][info->player.x] = 'P';
		(info->movement++);
	}
	ft_printf("number of moves : %d\n", info->movement);
	draw_player(info, keycode);
}

int	deal_key(int keycode, t_unit *info)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(info, keycode);
	return (0);
}
