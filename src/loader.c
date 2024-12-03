/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:17:48 by albillie          #+#    #+#             */
/*   Updated: 2024/12/03 21:49:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_render *game, char grid, int i, int j)
{
	if (grid == '0')
	{
		mlx_image_to_window(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
	}
	else if (grid == '1')
	{
		mlx_image_to_window(game->mlx, game->wall_txt, j * SIZE, i * SIZE);
	}
	else if (grid == 'C')
	{
		mlx_image_to_window(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
		mlx_image_to_window(game->mlx, game->collectible_txt, j * SIZE, i * SIZE);
	}
	else if (grid == 'E')
	{
		mlx_image_to_window(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
		mlx_image_to_window(game->mlx, game->exit_txt, j * SIZE, i * SIZE);
	}
	else if (grid == 'P')
	{
		mlx_image_to_window(game->mlx, game->ground_txt, j * SIZE, i * SIZE);
		mlx_image_to_window(game->mlx, game->player_txt, j * SIZE, i * SIZE);
	}
}

void	map_drawer(t_global *game) // TODO inverser les axes X - Y pour l'affichage
{
	printf("im here\n");
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			draw_map(&game->render, game->map.grid[i][j], i, j);
			j++;
		}
		i++;
	}
}

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

void	update_textures(t_global *game)
{
	if (game->map.grid[game->player.player_y][game->player.player_x] == 'E')
	{
		DRAW(game->render.mlx, game->render.player_txt, game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
		DRAW(game->render.mlx, game->render.exit_txt, game->player.player_x * SIZE, game->player.player_y * SIZE);
	}
	else
	{
		DRAW(game->render.mlx, game->render.player_txt, game->player.player_new_x * SIZE, game->player.player_new_y * SIZE);
		DRAW(game->render.mlx, game->render.ground_txt, game->player.player_x * SIZE, game->player.player_y * SIZE);
	}
}

void	collectible_handler(t_global *game)
{
	if (game->map.grid[game->player.player_new_y][game->player.player_new_x] == 'C')
	{
		ft_printf("You are on collectible");
		game->map.grid[game->player.player_new_y][game->player.player_new_x] = '0';
		game->map.collectible--;
		ft_printf("%d", game->map.collectible);
	}
	if (game->map.grid[game->player.player_new_y][game->player.player_new_x] == 'E' && game->map.collectible == 0)
	{
		mlx_close_window(game->render.mlx);
	}
}

void	close_game(t_global *game)
{
	mlx_delete_image(game->render.mlx, game->render.collectible_txt);
	mlx_delete_image(game->render.mlx, game->render.player_txt);
	mlx_delete_image(game->render.mlx, game->render.exit_txt);
	mlx_delete_image(game->render.mlx, game->render.ground_txt);
	mlx_delete_image(game->render.mlx, game->render.wall_txt);
	mlx_close_window(game->render.mlx);
	free_map(game->map.grid);
	free(game);
}
