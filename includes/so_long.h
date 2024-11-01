/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:12:36 by albillie          #+#    #+#             */
/*   Updated: 2024/11/01 16:38:04 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "/home/albillie/Desktop/SO-LONG-42/MLX-42/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/* typedef struct player {
} */

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




#endif
