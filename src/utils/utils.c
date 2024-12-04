/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:59 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 23:41:52 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_debug(char *msg)
{
	write(2, "[DEBUG]", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	free_exit(t_global *game, char *msg, int status)
{
	int	i;
	i = 0;

	if (status == 1)
	{
		ft_printf("Error\n%s\n", msg);
	}
	else if (status == 0)
	{
		ft_printf("%s\n", msg);
	}
	while(game->map.grid && game->map.grid[i])
	{
		free(game->map.grid[i++]);
	}
	free(game->map.grid);
	free(game);
	exit(1);
}

int	get_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return(height);
}
int get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	get_next_line(-1);
	close(fd);
	return (width);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'V' )
		return;
	map[y][x] = 'V';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, x, x - 1);
	flood_fill(map, x, x + 1);
}

void	copy_map(t_global *game)
{
	int	i;
	int	j;
	char	**map_copy;

	map_copy = malloc(sizeof(game->map.grid));
	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			map_copy[i][j] = game->map.grid[i][j];
			j++;
		}
		i++;
	}
	printf("%s", map_copy[0]);
}




void	verify_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'V')
			{
				ft_printf("this is invalid map path\n");
			}
			j++;
		}
		i++;
	}
}
