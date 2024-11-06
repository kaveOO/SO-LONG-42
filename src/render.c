/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:27 by albillie          #+#    #+#             */
/*   Updated: 2024/11/05 07:12:40 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/albillie/Desktop/SO-LONG-42/includes/so_long.h"

void	texture_loader(t_render *game)
{
	int		width;
	int		height;

	game->wall_img = mlx_texture_to_image(game->mlx,
		"./textures/wall.xpm", &width, &height);

	game->ground_img = mlx_xpm_file_to_image(game->mlx,
		"./textures/ground.xpm", &width, &height);

	game->player_img = mlx_xpm_file_to_image(game->mlx,
		"./textures/player.xpm", &width, &height);

	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
		"./textures/collectible.xpm", &width, &height);

	game->exit_img = mlx_xpm_file_to_image(game->mlx,
		"./textures/exit.xpm", &width, &height);

	if (!game->wall_img || !game->ground_img || !game->player_img ||
	!game->collectible_img || !game->exit_img)
	{
		printf("Error when loading textures !\n");
		exit(1);
	}
	printf("Sucessfully loaded textures !\n");
}
int main()
{
	t_render game;

	game.mlx = mlx_init();

	texture_loader(&game);

	mlx_loop(game.mlx);
}
