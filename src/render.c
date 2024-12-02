/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:28:27 by albillie          #+#    #+#             */
/*   Updated: 2024/12/02 20:05:55 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	texture_loader(t_render *game)
{
	game->wall_img = mlx_load_png("textures/wall.png");
	game->ground_img = mlx_load_png("textures/ground.png");
	game->player_img = mlx_load_png("textures/king.png");
	game->collectible_img[0] = mlx_load_png("textures/coin1.png");
	game->collectible_img[1] = mlx_load_png("textures/coin_2.png");
	game->collectible_img[2] = mlx_load_png("textures/coin_3.png");
	game->collectible_img[3] = mlx_load_png("textures/coin_4.png");
	game->collectible_img[4] = mlx_load_png("textures/coin_5.png");
	game->collectible_img[5] = mlx_load_png("textures/coin_6.png");
	game->collectible_img[6] = mlx_load_png("textures/coin_7.png");
	game->exit_img = mlx_load_png("textures/exit.png");

	// mlx_delete_texture(game->wall_img);
	// mlx_delete_texture(game->ground_img);
	// mlx_delete_texture(game->player_img);
	// mlx_delete_texture(game->exit_img);
	// mlx_delete_texture(game->collectible_img[0]);
	// mlx_delete_texture(game->collectible_img[1]);
	// mlx_delete_texture(game->collectible_img[2]);
	// mlx_delete_texture(game->collectible_img[3]);
	// mlx_delete_texture(game->collectible_img[4]);
	// mlx_delete_texture(game->collectible_img[5]);
	// mlx_delete_texture(game->collectible_img[6]);

	game->wall_txt = mlx_texture_to_image(game->mlx, game->wall_img);
	game->ground_txt = mlx_texture_to_image(game->mlx, game->ground_img);
	game->player_txt = mlx_texture_to_image(game->mlx, game->player_img);
	game->collectible_txt[0] = mlx_texture_to_image(game->mlx, game->collectible_img[0]);
	game->collectible_txt[1] = mlx_texture_to_image(game->mlx, game->collectible_img[1]);
	game->collectible_txt[2] = mlx_texture_to_image(game->mlx, game->collectible_img[2]);
	game->collectible_txt[3] = mlx_texture_to_image(game->mlx, game->collectible_img[3]);
	game->collectible_txt[4] = mlx_texture_to_image(game->mlx, game->collectible_img[4]);
	game->collectible_txt[5] = mlx_texture_to_image(game->mlx, game->collectible_img[5]);
	game->collectible_txt[6] = mlx_texture_to_image(game->mlx, game->collectible_img[6]);
	game->exit_txt = mlx_texture_to_image(game->mlx, game->exit_img);

	mlx_delete_texture(game->wall_img);
	mlx_delete_texture(game->ground_img);
	mlx_delete_texture(game->player_img);
	mlx_delete_texture(game->exit_img);
	mlx_delete_texture(game->collectible_img[0]);
	mlx_delete_texture(game->collectible_img[1]);
	mlx_delete_texture(game->collectible_img[2]);
	mlx_delete_texture(game->collectible_img[3]);
	mlx_delete_texture(game->collectible_img[4]);
	mlx_delete_texture(game->collectible_img[5]);
	mlx_delete_texture(game->collectible_img[6]);


	if (!game->wall_img || !game->ground_img || !game->player_img ||
	!game->collectible_img[0] || !game->exit_img)
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
		DRAW(game->mlx, game->ground_txt, j * TS, i * TS);
	}
	else if (grid == '1')
	{
		DRAW(game->mlx, game->wall_txt, j * TS, i * TS);
	}
	else if (grid == 'C')
	{
		DRAW(game->mlx, game->ground_txt, j * TS, i * TS);
		DRAW(game->mlx, game->collectible_txt[0], j * TS, i * TS);
	}
	else if (grid == 'E')
	{
		DRAW(game->mlx, game->ground_txt, j * TS, i * TS);
		DRAW(game->mlx, game->exit_txt, j * TS, i * TS);
	}
	else if (grid == 'P')
	{
		DRAW(game->mlx, game->ground_txt, j * TS, i * TS);
		DRAW(game->mlx, game->player_txt, j * TS, i * TS);
	}
}

void	loop_collectibles(void *param)
{
	t_render *game;

	game = (t_render *) param;
	DRAW(game->mlx, game->collectible_txt[0], 0 * TS, 0 * TS);
	DRAW(game->mlx, game->collectible_txt[1], 0 * TS, 0 * TS);
	DRAW(game->mlx, game->collectible_txt[2], 0 * TS, 0 * TS);
	DRAW(game->mlx, game->collectible_txt[3], 0 * TS, 0 * TS);
	DRAW(game->mlx, game->collectible_txt[4], 0 * TS, 0 * TS);
	DRAW(game->mlx, game->collectible_txt[5], 0 * TS, 0 * TS);
	DRAW(game->mlx, game->collectible_txt[6], 0 * TS, 0 * TS);
}
void	map_drawer(t_map *map, t_render *game) // TODO inverser les axes X - Y pour l'affichage
{
	printf("im here\n");
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			draw_map(game, map->grid[i][j], i, j);
			j++;
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
	map->height = 0;
	map->width = 0;
	map_checker(map);
	int i = 0;
	while (map->grid[i])
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	game->map = map;


	game->mlx = mlx_init(map->w_width * TS, map->w_height * TS, "SO LONG kaveo", false);
	if (!game->mlx)
	{
		printf("Error when init !\n");
	}
	texture_loader(game);
	map_drawer(map, game);
	player = (t_player *)malloc(sizeof(t_player));
	player->player_m = 0;
	get_player_pos(map, game, player);

	mlx_key_hook(game->mlx, change_direction, game);
	mlx_loop(game->mlx);
}

void	change_direction(mlx_key_data_t keydata, void *param)
{
	t_render *game;

	game = (t_render *) param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			close_game(game);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			check_direction(game, 'W');
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			check_direction(game, 'S');
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			check_direction(game, 'A');
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			check_direction(game, 'D');
	}
}

void	check_direction(t_render *game, char key)
{
	if (game->map->grid[game->player->player_y - 1]
		[game->player->player_x] != '1' && key == 'W')
	{
		moove_handler(game, 'W');
	}
	if (game->map->grid[game->player->player_y + 1]
		[game->player->player_x] != '1' && key == 'S')
	{
		moove_handler(game, 'S');
	}
	if (game->map->grid[game->player->player_y]
		[game->player->player_x - 1] != '1' && key == 'A')
	{
		moove_handler(game, 'A');
	}
	if (game->map->grid[game->player->player_y]
		[game->player->player_x + 1] != '1' && key == 'D')
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
	update_textures(game);
	game->player->player_x = game->player->player_new_x;
	game->player->player_y = game->player->player_new_y;
	game->player->player_m += 1;
	mlx_image_to_window(game->mlx, game->wall_txt, 0 * TS, 0 * TS);
	mlx_image_to_window(game->mlx, game->wall_txt, 1 * TS, 0 * TS);
	mlx_image_to_window(game->mlx, game->wall_txt, 2 * TS, 0 * TS);
	mlx_put_string(game->mlx, ft_itoa(game->player->player_m), 0, 0);
	collectible_handler(game);
}
void	update_textures(t_render *game)
{
	if (game->map->grid[game->player->player_y][game->player->player_x] == 'E')
	{
		DRAW(game->mlx, game->player_txt, game->player->player_new_x * TS, game->player->player_new_y * TS);
		DRAW(game->mlx, game->exit_txt, game->player->player_x * TS, game->player->player_y * TS);
	}
	else
	{
		DRAW(game->mlx, game->player_txt, game->player->player_new_x * TS, game->player->player_new_y * TS);
		DRAW(game->mlx, game->ground_txt, game->player->player_x * TS, game->player->player_y * TS);
	}
}

void	collectible_handler(t_render *game)
{
	if (game->map->grid[game->player->player_new_y][game->player->player_new_x] == 'C')
	{
		ft_printf("You are on collectible");
		game->map->grid[game->player->player_new_y][game->player->player_new_x] = '0';
		game->map->collectible--;
		ft_printf("%d", game->map->collectible);
	}
	if (game->map->grid[game->player->player_new_y][game->player->player_new_x] == 'E' && game->map->collectible == 0)
	{
		mlx_close_window(game->mlx);
	}
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
