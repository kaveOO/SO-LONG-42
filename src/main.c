/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:09:31 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 23:30:57 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_global *game;

	game = (t_global *) param;
	mlx_close_window(game->render.mlx);
	mlx_delete_image(game->render.mlx, game->render.collectible_txt[0]);
	mlx_delete_image(game->render.mlx, game->render.player_txt[1]);
	mlx_delete_image(game->render.mlx, game->render.exit_txt);
	mlx_delete_image(game->render.mlx, game->render.ground_txt);
	mlx_delete_image(game->render.mlx, game->render.wall_txt);
	mlx_terminate(game->render.mlx);
	free_exit(game, "Thanks you for playing, have a good day !", 0);
}

int main(int argc, char **argv)
{
	t_global *game;
	game = ft_calloc(1, sizeof(t_global));
	args_checker(game, argc, argv[1]);
	map_checker(game);
	game->render.mlx = mlx_init((game->map.width - 1) * SIZE, game->map.height * SIZE, "test", false);
	texture_loader(game);
	map_drawer(game);
	get_player_pos(game);

	mlx_key_hook(game->render.mlx, change_direction, game);
	mlx_close_hook(game->render.mlx, close_game, game);
	mlx_loop(game->render.mlx);
}
