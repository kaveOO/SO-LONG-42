/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:46:59 by albillie          #+#    #+#             */
/*   Updated: 2024/12/05 04:01:20 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_debug(char *msg)
{
	write(2, "[DEBUG]", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

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

int	get_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	get_next_line(-1);
	close(fd);
	return (width);
}
