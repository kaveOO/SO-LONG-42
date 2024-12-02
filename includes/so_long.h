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
#define TS 32

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
	int		w_height;
	int		w_width;
	int		collectible;
	int		exit;
	int		spawn;
} t_map;

typedef struct s_render {
	void	*mlx;
	void	*window;

	void	*wall_img;
	void	*ground_img;
	void	*player_img;
	void	*collectible_img[8];
	void	*exit_img;

	void	*wall_txt;
	void	*ground_txt;
	void	*player_txt;
	void	*collectible_txt[8];
	void	*exit_txt;
	t_player	*player;
	t_map		*map;
} t_render;

typedef struct s_global {
	t_player	*player;
	t_map		*map;
	t_render	*render;
} t_global;

// * GAME FUNCTIONS

void	args_checker(char *filename, int argc, t_map *map);
char	*get_next_line(int fd);
void	check_map_size(t_map *map);
void	free_map(char **map);
void	map_checker(t_map *map);
void	check_map_closure(t_map *map);
void	count_map_chars(t_map *map);
void	check_map_char(t_map *map);
void	exit_free(char *str, char **map);
bool	check_chars_counts(t_map *map);
void	get_height(t_map *map);
void	get_width(t_map *map);
void	fill_matrix(t_map *map);
void	hook(void *param);
void	moove_handler(t_render *game, char key);
void	change_direction(mlx_key_data_t keydata, void *param);
void	get_player_pos(t_map *map, t_render *game, t_player *player);
void	check_direction(t_render *game, char key);
void	close_game(t_render *render);
void	init_game(t_global *game);
void	collectible_handler(t_render *game);
void	update_textures(t_render *game);
void	loop_collectibles(void *param);


#endif
