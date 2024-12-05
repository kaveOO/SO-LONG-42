/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:00:17 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 03:59:42 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_images(t_global *game, const char *path)
{
	mlx_texture_t	*image;
	mlx_image_t		*texture;

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
	game->render.exit_txt = load_images(game, "textures/exit.png");
	game->render.collectible_txt = load_images(game, "textures/coin.png");
	game->render.gnome_txt = load_images(game, "textures/gnome.png");
	game->render.player_txt[0] = load_images(game, "textures/player1.png");
	game->render.player_txt[1] = load_images(game, "textures/player2.png");
	game->render.player_txt[2] = load_images(game, "textures/player3.png");
	game->render.player_txt[3] = load_images(game, "textures/player4.png");
}
