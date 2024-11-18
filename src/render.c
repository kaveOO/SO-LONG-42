/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:27 by albillie          #+#    #+#             */
/*   Updated: 2024/11/18 05:10:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/albillie/Desktop/SO-LONG-42/includes/so_long.h"

/* void	texture_loader(t_render *game)
{
	game->wall_img = mlx_texture_to_image(game->mlx,
		"./textures/wall.xpm");

	game->ground_img = mlx_texture_to_image(game->mlx,
		"./textures/ground.xpm");

	game->player_img = mlx_texture_to_image(game->mlx,
		"./textures/player.xpm");

	game->collectible_img = mlx_texture_to_image(game->mlx,
		"./textures/collectible.xpm");

	game->exit_img = mlx_texture_to_image(game->mlx,
		"./textures/exit.xpm");

	if (!game->wall_img || !game->ground_img || !game->player_img ||
	!game->collectible_img || !game->exit_img)
	{
		printf("Error when loading textures !\n");
		exit(1);
	}
	printf("Sucessfully loaded textures !\n");
} */

int main()
{
	t_render game;

	char *str = malloc(1);
	game.mlx = mlx_init(1920, 1080, "kaveO's SO_LONG", true);
	str[0] = 6 ;
	/* texture_loader(&game); */
	mlx_loop(game.mlx);
}
