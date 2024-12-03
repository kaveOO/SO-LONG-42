;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:12:36 by albillie          #+#    #+#             */
/*   Updated: 2024/11/01 22:29:45 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

#define DRAW mlx_image_to_window
#define SIZE 32

#include "../minilibx/mlx42.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// * GAME STRUCTURE

typedef struct s_player {
	int	player_x;
	int	player_y;
	int player_new_x;
	int player_new_y;
	int	player_m;
} t_player;

// * MAP STRUCTURE

typedef struct s_map {
	char	**grid;
	char	*filename;
	int		height;
	int		width;
	int		collectible;
	int		exit;
	int		spawn;
} t_map;

// * RENDER STRUCTURE

typedef struct s_render {
	void	*mlx;
	void	*window;

	void	*wall_img;
	void	*ground_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;

	void	*wall_txt;
	void	*ground_txt;
	void	*player_txt;
	void	*collectible_txt;
	void	*exit_txt;
} t_render;

typedef struct s_global {
	t_player	player;
	t_map		map;
	t_render	render;
} t_global;

// * GAME FUNCTIONS

char	*args_checker(int argc, char *filename);
char	*get_next_line(int fd);
void	check_map_size(t_map *map);
void	free_map(char **map);
void	map_checker(t_map *map);
void	check_map_closure(t_map *map);
void	count_map_chars(t_map *map);
void	check_map_char(t_map *map);
void	exit_free(char *str, char **map);
bool	check_chars_counts(t_map *map);
int		get_height(char *filename);
int		get_width(char *filename);
void	fill_matrix(t_map *map);
void	hook(void *param);
void	move_handler(t_global *game, char key);
void	change_direction(mlx_key_data_t keydata, void *param);
void	get_player_pos(t_global *game);
void	check_direction(t_global *game, char key);
void	close_game(t_global *game);
void	init_game(t_global *game);
void	collectible_handler(t_global *game);
void	update_textures(t_global *game);
void	loop_collectibles(void *param);
void	map_drawer(t_global *game);
void	texture_loader(t_render *render);
void	update_mooves_count(t_global *game);
void	update_player_pos(t_global *player);
void	map_init(t_map *map, int ac, char *av);
void	write_debug(char *msg);

#endif
