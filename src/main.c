/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:09:31 by albillie          #+#    #+#             */
/*   Updated: 2024/12/03 21:49:19 by albillie         ###   ########.fr       */
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
	map_init(&((*game).map), argc, argv[1]);
	map_checker(&game->map);
	printf("%d", game->map.width);
	game->render.mlx = mlx_init((game->map.width - 1) * SIZE, game->map.height * SIZE, "test", false);
	texture_loader(&game->render);
	map_drawer(game);
	get_player_pos(game);

	mlx_key_hook(game->render.mlx, change_direction, game);
	mlx_loop(game->render.mlx);
	mlx_terminate(game->render.mlx);
}
