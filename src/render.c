/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:27 by albillie          #+#    #+#             */
/*   Updated: 2024/11/29 23:26:54 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/albillie/Desktop/SO-LONG-42/includes/so_long.h"

void	texture_loader(t_render *game)
{
	game->wall_img = mlx_texture_to_image(game->mlx,
		"./textures/wall.xpm");

	game->ground_img = mlx_texture_to_image(game->mlx,
		"./textures/ground.xpm");

	game->player_img = mlx_load_png("");
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
}

int main()
{
	void *mlx;
	void *img;

	mlx = mlx_init(1920, 1080, "SO LONG kaveo", true);
	img = mlx_load_xpm42("textures/exit.xpm");
	mlx_image_to_wreindow(mlx, img, 0, 0);
	mlx_loop(mlx);
}
