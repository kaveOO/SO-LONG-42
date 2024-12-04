/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:48:03 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 08:28:53 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill(t_global *game, int x, int y)
{
	int north;
	int south;
	int east;
	int west;
	char	grid;


	printf("%d\n", x);
	printf("%d\n", y);

	grid = game->map.grid[y][x];
	if (grid == '1' || grid == 'C' || grid == 'V' || (grid == 'P' && x != game->player.player_x) || y != game->player.player_y)
		return 0;

	if (grid == 'E')
		return 1;

	if (grid == '0')
		game->map.grid[y][x] = 'V';

	// ft_printf("%s\n", game->map.grid[y]);
	north = flood_fill(game, x, y - 1);
	south = flood_fill(game, x, y + 1);
	east = flood_fill(game, x + 1, y);
	west = flood_fill(game, x - 1, y);
	if (north || south || east || west)
	{
		return 1;
	}
	return 0;
}
