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
	int		height;
	int		width;
} t_map;

typedef struct s_render {
	void	*wall_img;
	void	*ground_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;

	int		*img_width;
	int		*img_height;
} t_render;

void	args_checker(char *filename, int argc);
char	*get_next_line(int fd);
void	check_map_size(char **map, int width, int height);
void	free_map(char **map);
void	map_checker(char **map, int width, int height);
void	check_map_closure(char **map, int width, int height);
void	check_map_char(char **map);


#endif
