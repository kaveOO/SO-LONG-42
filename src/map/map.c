/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:38:28 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 03:00:35 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_global *game)
{
	game->map.height = get_height(game->map.filename);
	game->map.width = get_width(game->map.filename);
	fill_matrix(game);
	get_player_pos(game);
	check_map_size(game);
	check_map_closure(game);
	check_map_char(game);
	count_map_chars(game);
	if (!check_chars_counts(game))
		free_exit(game, "Invalid count of characters on the map !", 1);
	check_map(game);
}

void	fill_matrix(t_global *game)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;

	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	fd = open(game->map.filename, O_RDONLY);
	line = get_next_line(fd);
	tmp = line;
	tmp = ft_strtrim(tmp, "\n");
	free(line);
	game->map.grid[0] = tmp;
	i = 1;
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		tmp = line;
		tmp = ft_strtrim(tmp, "\n");
		free(line);
		game->map.grid[i] = tmp;
		i++;
	}
	game->map.grid[i] = NULL;
	get_next_line(-1);
	close(fd);
}

void	map_drawer(t_global *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			draw_map(&game->render, game->map.grid[i][j], i, j);
			j++;
		}
		i++;
	}
}
