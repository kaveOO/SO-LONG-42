/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:07:42 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 23:31:41 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_direction(mlx_key_data_t keydata, void *param)
{
	t_global *game;

	game = (t_global *) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			close_game(game);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			check_direction(game, 'W');
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			check_direction(game, 'S');
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			check_direction(game, 'A');
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			check_direction(game, 'D');
	}
}

void	check_direction(t_global *game, char key)
{
	if (game->map.grid[game->player.player_y - 1]
		[game->player.player_x] != '1' && key == 'W')
	{
		move_handler(game, 'W');
	}
	if (game->map.grid[game->player.player_y + 1]
		[game->player.player_x] != '1' && key == 'S')
	{
		move_handler(game, 'S');
	}
	if (game->map.grid[game->player.player_y]
		[game->player.player_x - 1] != '1' && key == 'A')
	{
		move_handler(game, 'A');
	}
	if (game->map.grid[game->player.player_y]
		[game->player.player_x + 1] != '1' && key == 'D')
	{
		move_handler(game, 'D');
	}
}

void	move_handler(t_global *game, char key)
{
	if (key == 'W')
	{
		game->player.player_new_x = game->player.player_x;
		game->player.player_new_y = game->player.player_y - 1;
	}
	else if (key == 'S')
	{
		game->player.player_new_x = game->player.player_x;
		game->player.player_new_y = game->player.player_y + 1;
	}
	else if (key == 'A')
	{
		game->player.player_new_x = game->player.player_x - 1;
		game->player.player_new_y = game->player.player_y;
	}
	else if (key == 'D')
	{
		game->player.player_new_x = game->player.player_x + 1;
		game->player.player_new_y = game->player.player_y;
	}
	update_player_txt(game, key);
	update_position(game);
	draw_mooves(game);
	collectible_handler(game);
}



