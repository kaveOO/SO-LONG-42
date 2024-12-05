/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 13:28:13 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_size(t_global *game)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(game->map.grid[i++]);
	while (game->map.grid[i])
	{
		if (ft_strlen(game->map.grid[i]) != ref)
		{
			free_exit(game, "Invalid map line length on line !", 1);
		}
		i++;
	}
	if (game->map.width == game->map.height)
	{
		free_exit(game, "Your map is square !", 1);
	}
}

void	check_map_closure(t_global *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		if (game->map.grid[i][0] != '1')
			free_exit(game, "Invalid enclosure on left side !", 1);
		else if (game->map.grid[i][game->map.width - 2] != '1')
			free_exit(game, "Invalid enclosure on right side !", 1);
		while (game->map.grid[i][j])
		{
			if (game->map.grid[0][j] != '1')
				free_exit(game, "Invalid enclosure on top side !", 1);
			else if (game->map.grid[game->map.height - 1][j] != '1')
				free_exit(game, "Invalid enclosure on bottom side !", 1);
			j++;
		}
		i++;
	}
}

void	check_map_char(t_global *game)
{
	size_t	i;
	size_t	j;
	char	*chars;

	i = 0;
	chars = "01CEPG";
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (!strchr(chars, game->map.grid[i][j]))
			{
				free_exit(game, "Invalid characters in map !", 1);
			}
			j++;
		}
		i++;
	}
}

void	count_map_chars(t_global *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (game->map.grid[i][j] == 'C')
				game->map.collectible++;
			if (game->map.grid[i][j] == 'E')
				game->map.exit++;
			if (game->map.grid[i][j] == 'P')
				game->map.spawn++;
			j++;
		}
		i++;
	}
}

bool	check_chars_counts(t_global *game)
{
	if (game->map.collectible < 1)
	{
		return (false);
	}
	if (game->map.exit < 1 || game->map.exit > 1)
	{
		return (false);
	}
	if (game->map.spawn < 1 || game->map.spawn > 1)
	{
		return (false);
	}
	return (true);
}
