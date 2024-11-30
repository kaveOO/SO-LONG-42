/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:27 by albillie          #+#    #+#             */
/*   Updated: 2024/11/30 06:08:02 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	texture_loader(t_render *game)
{
	game->wall_img = mlx_load_png("textures/wall.png");
	game->ground_img = mlx_load_png("textures/ground.png");
	game->player_img = mlx_load_png("textures/goblin1.png");
	game->collectible_img = mlx_load_png("textures/coin1.png");
	game->exit_img = mlx_load_png("textures/exit.png");

	game->wall_txt = mlx_texture_to_image(game->mlx, game->wall_img);
	game->ground_txt = mlx_texture_to_image(game->mlx, game->ground_img);
	game->player_txt = mlx_texture_to_image(game->mlx, game->player_img);
	game->collectible_txt = mlx_texture_to_image(game->mlx, game->collectible_img);
	game->exit_txt = mlx_texture_to_image(game->mlx, game->exit_img);


	if (!game->wall_img || !game->ground_img || !game->player_img ||
	!game->collectible_img || !game->exit_img)
	{
		printf("Error when loading textures !\n");
		exit(1);
	}
	printf("Sucessfully loaded textures !\n");
}

void draw_map(t_render *game, char grid, int i, int j)
{
	if (grid == '0')
	{
		DRAW(game->mlx, game->ground_txt, j * 40, i * 40);
	}
	else if (grid == '1')
	{
		printf("avant\n");
		DRAW(game->mlx, game->wall_txt, j * 40, i * 40);
		printf("apres\n");
	}
	else if (grid == 'C')
	{
		DRAW(game->mlx, game->ground_txt, j * 40, i * 40);
		DRAW(game->mlx, game->collectible_txt, j * 40 + 5, i * 40 + 5);
	}
	else if (grid == 'E')
	{
		DRAW(game->mlx, game->ground_txt, j * 40, i * 40);
		DRAW(game->mlx, game->exit_txt, j * 40, i * 40);
	}
	else if (grid == 'P')
	{
		DRAW(game->mlx, game->ground_txt, j * 40, i * 40);
		DRAW(game->mlx, game->player_txt, j * 40, i * 40);
	}
}

void	map_drawer(t_map *map, t_render *game) // TODO inverser les axes X - Y pour l'affichage
{
	printf("im here\n");
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = map->width - 2;
		while (map->grid[i][j])
		{
			printf("%c\n", map->grid[i][j]);
			draw_map(game, map->grid[i][j], i, j);
			j--;
		}
		i++;
	}
}
/* int main()
{
	t_render *game;
	t_map 	*map;

	game = (t_render *)malloc(sizeof(t_render));
	map = (t_map *)malloc(sizeof(t_map));

	texture_loader(game);
	map_drawer(map, game);
} */

int main(int argc, char **argv)
{
	t_render *game;
	t_map *map;

	game = (t_render *)malloc(sizeof(t_render)); // free
	map = (t_map *)malloc(sizeof(t_map)); // free

	args_checker(argv[1], argc);
	map->height = get_height(argv[1]);
	map->width = get_width(argv[1]);
	map->grid = fill_matrix(map->grid, argv[1], map->height);
	map_checker(map->grid, map->width, map->height);

	game->mlx = mlx_init(1920, 1080, "SO LONG kaveo", true);
	if (!game->mlx)
	{
		printf("Error when init !\n");
	}

	texture_loader(game);
	map_drawer(map, game);

	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->wall_img);
	mlx_delete_image(game->mlx, game->wall_txt);
}
