/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:59 by albillie          #+#    #+#             */
/*   Updated: 2024/12/09 01:44:32 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	write_debug(char *msg)
// {
// 	write(2, "[DEBUG]", 7);
// 	write(2, msg, ft_strlen(msg));
// 	write(2, "\n", 1);
// }

void	free_exit(t_global *game, char *msg, int status)
{
	int	i;

	i = 0;
	if (status == 1)
	{
		ft_printf("Error\n%s\n", msg);
	}
	else if (status == 0)
	{
		ft_printf("%s\n", msg);
	}
	while (game->map.grid && game->map.grid[i])
	{
		free(game->map.grid[i++]);
	}
	free(game->map.grid);
	free(game);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i++]);
	}
	free(map);
}

void	get_height(t_global *game)
{
	int		fd;
	char	*line;

	fd = open(game->map.filename, O_RDONLY);
	if (fd < 0)
		free_exit(game, "Failed to open map in get_height !", 1);
	line = get_next_line(fd);
	if (!line)
	{
		free_exit(game, "Map is empty !", 1);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->map.height++;
	}
	free(line);
	close(fd);
}

void	get_width(t_global *game)
{
	int		fd;
	char	*line;

	fd = open(game->map.filename, O_RDONLY);
	if (fd < 0)
		free_exit(game, "Failed to open map in get_width !", 1);
	line = get_next_line(fd);
	if (!line)
	{
		free_exit(game, "Map is empty !", 1);
	}
	game->map.width = ft_strlen(line);
	free(line);
	get_next_line(-1);
	close(fd);
}
