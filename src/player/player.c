/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:49:05 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 23:07:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_global *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map.grid[i])
		{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (game->map.grid[i][j] == 'P')
			{
				game->player.player_x = j;
				game->player.player_y = i;
				break;
			}
			j++;
		}
		i++;
	}
}
void	update_position(t_global *game)
{
	game->player.player_x = game->player.player_new_x;
	game->player.player_y = game->player.player_new_y;
	game->player.player_m += 1;
}

