/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:27 by albillie          #+#    #+#             */
/*   Updated: 2024/12/01 19:41:08 by albillie         ###   ########.fr       */
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
		DRAW(game->mlx, game->wall_txt, j * 40, i * 40);
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
			draw_map(game, map->grid[i][j], i, j);
			j--;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_render *game;
	t_map *map;
	t_player *player;

	game = (t_render *)malloc(sizeof(t_render)); // free
	map = (t_map *)malloc(sizeof(t_map)); // free

	args_checker(argv[1], argc, map);
	map_checker(map);
	int i = 0;
	while (map->grid[i])
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	game->map = map;


	game->mlx = mlx_init(map->w_width * 40, map->w_height * 40, "SO LONG kaveo", false);
	if (!game->mlx)
	{
		printf("Error when init !\n");
	}
	texture_loader(game);
	map_drawer(map, game);
	player = (t_player *)malloc(sizeof(t_player));
	get_player_pos(map, game, player);
	ft_printf("%s", map->grid[1]);

	mlx_key_hook(game->mlx, change_direction, game);
	// mlx_loop_hook(game->mlx, &hook, (player, game->mlx));

	mlx_loop(game->mlx);
	exit_free("etetete", map->grid);
}

void	change_direction(mlx_key_data_t keydata, void *param)
{
	t_render *game;

	game = (t_render *) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx); //TODO Make function to free all the data then close the window properly
		}
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		{
			check_direction(game, 'W');
		}
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		{
			check_direction(game, 'S');
		}
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			check_direction(game, 'A');
		}
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			check_direction(game, 'D');
		}
	}
}

void	check_direction(t_render *game, char key)
{
	if (game->map->grid[game->player->player_y - 1][game->player->player_x] != '1' && key == 'W')
	{
		moove_handler(game, 'W');
	}
	if (game->map->grid[game->player->player_y + 1][game->player->player_x] != '1' && key == 'S')
	{
		moove_handler(game, 'S');
	}
	if (game->map->grid[game->player->player_y][game->player->player_x - 1] != '1' && key == 'A')
	{
		moove_handler(game, 'A');
	}
	if (game->map->grid[game->player->player_y][game->player->player_x + 1] != '1' && key == 'D')
	{
		moove_handler(game, 'D');
	}
}

void	moove_handler(t_render *game, char key)
{
	if (key == 'W')
	{
		game->player->player_new_x = game->player->player_x;
		game->player->player_new_y = game->player->player_y - 1;
	}
	else if (key == 'S')
	{
		game->player->player_new_x = game->player->player_x;
		game->player->player_new_y = game->player->player_y + 1;
	}
	else if (key == 'A')
	{
		game->player->player_new_x = game->player->player_x - 1;
		game->player->player_new_y = game->player->player_y;
	}
	else if (key == 'D')
	{
		game->player->player_new_x = game->player->player_x + 1;
		game->player->player_new_y = game->player->player_y;
	}
	DRAW(game->mlx, game->player_txt, game->player->player_new_x * 40, game->player->player_new_y * 40);
	DRAW(game->mlx, game->ground_txt, game->player->player_x * 40, game->player->player_y * 40);
	game->player->player_x = game->player->player_new_x;
	game->player->player_y = game->player->player_new_y;
}

void	get_player_pos(t_map *map, t_render *game, t_player *player)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P')
			{
				player->player_x = j;
				player->player_y = i;
				break;
			}
			j++;
		}
		i++;
	}
	game->player = player;
}
