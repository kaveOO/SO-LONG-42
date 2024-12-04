/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemenSIZE.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:03:09 by albillie          #+#    #+#             */
/*   Updated: 2024/12/03 20:00:18 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	i;

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

static int i = 0;

void	update_player_txt(t_global *game, char key)
{
	if (key == 'W')
	{
		i = 1;
		DRAW(game->render.mlx, game->render.player_txt[1], game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
	}
	else if (key == 'S')
	{
		i = 0;
		DRAW(game->render.mlx, game->render.player_txt[0], game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
	}
	else if (key == 'A')
	{
		i = 2;
		DRAW(game->render.mlx, game->render.player_txt[2], game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
	}
	else if (key == 'D')
	{
		i = 3;
		DRAW(game->render.mlx, game->render.player_txt[3], game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
	}
}

void	move_handler(t_global *game, char key)
{
	if (key == 'W')
	{
		game->player.player_new_x = game->player.player_x;
		game->player.player_new_y = game->player.player_y - 1;
		update_player_txt(game, key);
	}
	else if (key == 'S')
	{
		game->player.player_new_x = game->player.player_x;
		game->player.player_new_y = game->player.player_y + 1;
		update_player_txt(game, key);
	}
	else if (key == 'A')
	{
		game->player.player_new_x = game->player.player_x - 1;
		game->player.player_new_y = game->player.player_y;
		update_player_txt(game, key);
	}
	else if (key == 'D')
	{
		game->player.player_new_x = game->player.player_x + 1;
		game->player.player_new_y = game->player.player_y;
		update_player_txt(game, key);
	}
	update_textures(game);
	update_player_pos(game);
	update_mooves_count(game);
	collectible_handler(game);
}

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
void	update_player_pos(t_global *game)
{
	game->player.player_x = game->player.player_new_x;
	game->player.player_y = game->player.player_new_y;
	game->player.player_m += 1;
}

void	update_mooves_count(t_global *game)
{
	DRAW(game->render.mlx, game->render.wall_txt, 0 * SIZE, 0 * SIZE);
	DRAW(game->render.mlx, game->render.wall_txt, 1 * SIZE, 0 * SIZE);
	DRAW(game->render.mlx, game->render.wall_txt, 2 * SIZE, 0 * SIZE);
	mlx_put_string(game->render.mlx, ft_itoa(game->player.player_m), 5, 5);
}


void	collectible_handler(t_global *game)
{
	if (game->map.grid[game->player.player_new_y][game->player.player_new_x]
		== 'C')
	{
		DRAW(game->render.mlx, game->render.ground_txt,
		 	game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
		DRAW(game->render.mlx, game->render.player_txt[i],
			game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
		game->map.grid[game->player.player_new_y][game->player.player_new_x]
			= '0';
		game->map.collectible--;
	}
	if (game->map.grid[game->player.player_new_y][game->player.player_new_x]
		== 'E' && game->map.collectible == 0)
	{
		close_game(game);
	}
}
