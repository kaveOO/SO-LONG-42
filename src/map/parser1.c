/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 03:00:15 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 03:53:57 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'G' || map[y][x] == 'V')
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
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
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
