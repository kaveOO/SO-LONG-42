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
#include "../gnl/get_next_line.h"
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
	void	*mlx;
	void	*window;

	void	*wall_img;
	void	*ground_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;

	int		*img_width;
	int		*img_height;
} t_render;

void	map_checker(int argc, char **argv);
char	*get_next_line(int fd);

#endif
