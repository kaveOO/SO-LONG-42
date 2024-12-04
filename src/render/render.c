/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:51:15 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 23:07:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	i;

void	draw_mooves(t_global *game)
{
	DRAW(game->render.mlx, game->render.wall_txt, 0 * SIZE, 0 * SIZE);
	DRAW(game->render.mlx, game->render.wall_txt, 1 * SIZE, 0 * SIZE);
	DRAW(game->render.mlx, game->render.wall_txt, 2 * SIZE, 0 * SIZE);
	mlx_put_string(game->render.mlx, ft_itoa(game->player.player_m), 5, 5);
}

void	draw_map(t_render *game, char grid, int i, int j)
{
	if (grid == '0')
	{
		DRAW(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
	}
	else if (grid == '1')
	{
		DRAW(game->mlx, game->wall_txt, j * SIZE, i * SIZE);
	}
	else if (grid == 'C')
	{
		DRAW(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
		DRAW(game->mlx, game->collectible_txt[0], j * SIZE, i * SIZE);
	}
	else if (grid == 'E')
	{
		DRAW(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
		DRAW(game->mlx, game->exit_txt, j * SIZE, i * SIZE);
	}
	else if (grid == 'P')
	{
		DRAW(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
		DRAW(game->mlx, game->player_txt[0], j * SIZE, i * SIZE);
	}
}

void	exit_keeper(t_global *game)
{
	if (game->map.grid[game->player.player_y][game->player.player_x] == 'E')
	{
		ft_printf("i'm on the exit !");
		DRAW(game->render.mlx, game->render.exit_txt, game->player.player_x * SIZE, game->player.player_y * SIZE);
	}
	else
	{
		DRAW(game->render.mlx, game->render.ground_txt, game->player.player_x * SIZE, game->player.player_y * SIZE);
	}
}
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
	exit_keeper(game);
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
