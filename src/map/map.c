/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:38:28 by albillie          #+#    #+#             */
/*   Updated: 2024/12/09 01:56:24 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_global *game)
{
	get_height(game);
	get_width(game);
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

	fd = open(game->map.filename, O_RDONLY);
	if (fd < 0)
		free_exit(game, "Failed to open map in fill_matrix !", 1);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	game->map.grid[0] = get_and_trim(fd);
	i = 1;
	while (i < game->map.height)
	{
		game->map.grid[i] = get_and_trim(fd);
		i++;
	}
	game->map.grid[i] = NULL;
	get_next_line(-1);
	close(fd);
}

char	*get_and_trim(int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	tmp = line;
	tmp = ft_strtrim(tmp, "\n");
	free(line);
	return (tmp);
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
