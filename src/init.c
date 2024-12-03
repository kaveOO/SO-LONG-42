/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:20:38 by albillie          #+#    #+#             */
/*   Updated: 2024/12/03 21:28:07 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_init(t_map *map, int ac, char *av)
{
	map->filename = args_checker(ac, av);
	map->height = get_height(map->filename);
	map->width = get_width(map->filename);
}

void	texture_loader(t_render *render)
{
	render->wall_img = mlx_load_png("textures/wall.png");
	render->ground_img = mlx_load_png("textures/ground.png");
	render->player_img = mlx_load_png("textures/king.png");
	render->collectible_img = mlx_load_png("textures/coin1.png");
	render->exit_img = mlx_load_png("textures/exit.png");

	render->wall_txt = mlx_texture_to_image(render->mlx, render->wall_img);
	render->ground_txt = mlx_texture_to_image(render->mlx, render->ground_img);
	render->player_txt = mlx_texture_to_image(render->mlx, render->player_img);
	render->collectible_txt = mlx_texture_to_image(render->mlx, render->collectible_img);
	render->exit_txt = mlx_texture_to_image(render->mlx, render->exit_img);

	mlx_delete_texture(render->wall_img);
	mlx_delete_texture(render->ground_img);
	mlx_delete_texture(render->player_img);
	mlx_delete_texture(render->exit_img);
	mlx_delete_texture(render->collectible_img);
}

