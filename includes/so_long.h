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

#include "../minilibx/mlx42.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct s_player {
	int	player_x;
	int	player_y;
	int	player_m;
} t_player;

typedef struct s_map {
	char	**grid;
	char	*filename;
	int		height;
	int		width;
} t_map;

typedef struct s_elements {
	int		collectible;
	int		exit;
	int		spawn;
} t_elements;

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

	int		*img_width;
	int		*img_height;
} t_render;

void	args_checker(char *filename, int argc, t_map *map);
char	*get_next_line(int fd);
void	check_map_size(t_map *map);
void	free_map(char **map);
void	map_checker(t_map *map);
void	check_map_closure(t_map *map);
void	count_map_chars(t_map *map, t_elements *elements);
void	check_map_char(t_map *map);
void	exit_free(char *str, char **map);
bool	check_chars_counts(t_elements *elements);
void	get_height(t_map *map);
void	get_width(t_map *map);
void	fill_matrix(t_map *map);
void	hook(void *param);


#endif
