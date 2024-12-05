/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:12:36 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 04:08:01 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define DRAW mlx_image_to_window
# define SIZE 32

# include "../minilibx/mlx42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

// * GAME STRUCTURE

typedef struct s_player
{
	int	player_x;
	int	player_y;
	int	player_new_x;
	int	player_new_y;
	int	player_m;
}	t_player;

// * MAP STRUCTURE

typedef struct s_map
{
	char	**grid;
	char	*filename;
	int		height;
	int		width;
	int		collectible;
	int		exit;
	int		spawn;
}	t_map;

// * RENDER STRUCTURE

typedef struct s_render
{
	void	*mlx;
	void	*window;

	void	*wall_txt;
	void	*ground_txt;
	void	*player_txt[4];
	void	*gnome_txt;
	void	*collectible_txt;
	void	*exit_txt;
	int		angle;
}	t_render;

// * GLOBAL STRUCTURE

typedef struct s_global
{
	t_player	player;
	t_map		map;
	t_render	render;
}	t_global;

// * GAME FUNCTIONS

void	args_checker(t_global *game, int argc, char *filename);
char	*get_next_line(int fd);
void	check_map_size(t_global *game);
void	free_exit(t_global *game, char *msg, int status);
void	map_checker(t_global *game);
void	check_map_closure(t_global *game);
void	count_map_chars(t_global *game);
void	check_map_char(t_global *game);
bool	check_chars_counts(t_global *game);
int		get_height(char *filename);
int		get_width(char *filename);
void	fill_matrix(t_global *game);
void	move_handler(t_global *game, char key);
void	change_direction(mlx_key_data_t keydata, void *param);
void	get_player_pos(t_global *game);
void	check_direction(t_global *game, char key);
void	close_game(void *param);
void	collectible_handler(t_global *game);
void	map_drawer(t_global *game);
void	texture_loader(t_global *game);
void	draw_mooves(t_global *game);
void	update_position(t_global *game);
void	write_debug(char *msg);
void	flood_fill(char **map, int y, int x);
void	draw_map(t_render *game, char grid, int i, int j);
void	update_player_txt(t_global *game, char key);
char	**copy_map(t_global *game);
bool	verify_path(char **map);
void	check_map(t_global *game);
void	free_map(char **map);

#endif
