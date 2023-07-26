#include "so_long.h"

int	name_check(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (file[--len] == 'r')
	{
		if (file[--len] == 'e')
		{
			if (file[--len] == 'b')
			{
				if (file[--len] == '.')
					return (1);
			}
		}
	}
	return (0);
}

int	linecount(char *file)
{
	int		fd;
	int		line;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line = 0;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}

char	**malloc_height(t_unit *info, char *file)
{
	char	**map;
	int		line;

	line = linecount(file);
	if (line <= 0)
		return (0);
	info->map_height = line;
	map = (char **)malloc(sizeof(char *) * (line + 1));
	if (map == NULL)
		return (0);
	return (map);
}

void	load_map(t_unit *info, char *file)
{
	int	i;
	int	fd;

	if (!name_check(file))
	{
		ft_printf("bad extension");
		exit(0);
	}
	info->map = malloc_height(info, file);
	if (info->map == 0)
	{
		ft_printf("map height didnt buffer");
		exit(0);
	}
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &info->map[i]))
		i++;
	info->map_width = ft_strlen(info->map[0]);
	info->map[i] = 0;
	close(fd);
}
