/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:59 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 02:31:37 by albillie         ###   ########.fr       */
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map && map[i])
	{
		free(map[i++]);
	}
	free(map);
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

void	check_map(t_global *game)
{
	char	**map;

	map = copy_map(game);
	if (!map)
	{
		free_exit(game, "Error when copying the map !", 1);
	}
	flood_fill(map, game->player.player_y, game->player.player_x);
	if (!verify_path(map))
	{
		free_map(map);
		free_exit(game, "Invalid map path !", 1);
	}
	free_map(map);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1'|| map[y][x] == 'G' || map[y][x] == 'V'  )
		return ;
	map[y][x] = 'V';

	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

char	**copy_map(t_global *game)
{
	int		i;
	int		y;
	char	**map_copy;

	y = get_height(game->map.filename);
	map_copy = (char **)malloc(sizeof(char *) * (y + 1));
	i = 0;
	ft_memset(map_copy, 0, sizeof(char *) * (y + 1));
	while (i < y)
	{
		map_copy[i] = ft_strdup(game->map.grid[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

bool	verify_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				return false;
			}
			j++;
		}
		i++;
	}
	return true;
}
