/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:20:38 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 01:17:21 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*load_images(t_global *game ,const char *path)
{
	mlx_texture_t	*image;
	mlx_image_t	*texture;

	image = mlx_load_png(path);
	if (!image)
	{
		free_exit(game, "Failed to load textures", 1);
	}
	texture = mlx_texture_to_image(game->render.mlx, image);
	mlx_delete_texture(image);
	return (texture);
}

void	texture_loader(t_global *game)
{

	game->render.wall_txt = load_images(game, "textures/wall.png");
	game->render.ground_txt = load_images(game, "textures/ground.png");
	game->render.player_txt = load_images(game, "textures/king.png");
	game->render.exit_txt = load_images(game, "textures/exit.png");

	game->render.collectible_txt[0] = load_images(game, "textures/coin1.png");
	game->render.collectible_txt[1] = load_images(game, "textures/coin2.png");
	game->render.collectible_txt[2] = load_images(game, "textures/coin3.png");
	game->render.collectible_txt[3] = load_images(game, "textures/coin4.png");
	game->render.collectible_txt[4] = load_images(game, "textures/coin5.png");
	game->render.collectible_txt[5] = load_images(game, "textures/coin6.png");
	game->render.collectible_txt[6] = load_images(game, "textures/coin7.png");
	game->render.collectible_txt[7] = load_images(game, "textures/coin8.png");
}

