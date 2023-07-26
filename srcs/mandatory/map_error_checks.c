#include "so_long.h"

void	check_char(t_unit *info, int i, int j)
{
	if (!is_valid_char(info->map[i][j]))
	{
		ft_printf("Map characters other than 0, 1, C, E, P");
		exit(0);
	}
	if (i == 0 || i == info->map_height - 1
		|| j == 0 || j == info->map_width - 1)
	{
		if (info->map[i][j] != '1')
		{
			ft_printf("map has no 1 in perimeter");
			exit(0);
		}
	}
}

void	init_ready(t_content *map)
{
	map->player = 0;
	map->coin = 0;
	map->end = 0;
}

void	check_map_content(t_unit *info, int i, int j, t_content *map)
{
	if (info->map[i][j] == 'P')
		map->player++;
	else if (info->map[i][j] == 'C')
		map->coin++;
	else if (info->map[i][j] == 'E')
		map->end++;
}

void	check_ready(t_content ready)
{
	if (ready.player != 1)
	{
		ft_printf("map should have 1 player");
		exit(0);
	}
	else if (ready.coin == 0)
	{
		ft_printf("map should have at least 1 coin");
		exit(0);
	}
	else if (ready.end == 0)
	{
		ft_printf("map should have at least 1 exit");
		exit(0);
	}
}

void	check_map(t_unit *info)
{
	t_content	content;
	int			i;
	int			j;

	i = 0;
	init_ready(&content);
	while (i < info->map_height)
	{
		j = 0;
		if (ft_strlen(info->map[i]) != info->map_width)
		{
			ft_printf("map is not a rectangle");
			exit(0);
		}
		while (j < info->map_width)
		{
			check_char(info, i, j);
			check_map_content(info, i, j, &content);
			j++;
		}
		i++;
	}
	check_ready(content);
}
