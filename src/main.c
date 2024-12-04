/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:09:31 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 01:04:54 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	write_debug(char *msg)
{
	write(2, "[DEBUG]", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
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

	// mlx_loop_hook(game->render.mlx, ,game,)
	mlx_key_hook(game->render.mlx, change_direction, game);
	mlx_close_hook(game->render.mlx, close_game, game);
	mlx_loop(game->render.mlx);
}
