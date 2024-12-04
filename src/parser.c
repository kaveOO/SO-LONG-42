/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/12/04 08:16:54 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	args_checker(t_global *game, int argc, char *filename)
{
	if (argc < 2)
	{
		free_exit(game, "Please enter map name !", 1);
	}
	else if (argc > 2)
	{
		free_exit(game, "You have too much arguments !", 1);
	}
	if (!check_if_opened(filename))
	{
		free_exit(game, "Invalid map name !", 1);
	}
	if (!check_extension(filename, "ber"))
	{
		free_exit(game, "Map file extension is invalid !", 1);
	}
	game->map.filename = filename;
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
	return(height);
}
int get_width(char *filename)
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
void	map_checker(t_global *game)
{
	game->map.height = get_height(game->map.filename);
	game->map.width = get_width(game->map.filename);
	fill_matrix(game);
	get_player_pos(game);
	ft_printf("%d\n", flood_fill(game, game->player.player_x, game->player.player_y));
	check_map_size(game);
	check_map_closure(game);
	check_map_char(game);
	count_map_chars(game);
	if (!check_chars_counts(game))
		free_exit(game, "Invalid count of characters on the map !", 1);
}
void	check_map_closure(t_global *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.grid[j][i])
	{
		if (game->map.grid[0][i] != '1' ||
			game->map.grid[game->map.height - 1][i] != '1')
			free_exit(game, "Invalid characters on first or/and last line !", 1);
		while (j > 0)
		{
			if (game->map.grid[j][game->map.width - 4] != '1' ||
				game->map.grid[j][0] != '1')
			{
				free_exit(game, "Invalid enclosure on sides !", 1);
			}
			j--;
		}
		i++;
	}
}
void	check_map_char(t_global *game)
{
	size_t	i;
	size_t	j;
	char	*chars;

	i = 0;
	chars = "01CEP";
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (!strchr(chars, game->map.grid[i][j]))
			{
				free_exit(game, "Invalid characters in map !", 1);
			}
			j++;
		}
		i++;
	}
}
void	count_map_chars(t_global *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (game->map.grid[i][j] == 'C')
				game->map.collectible++;
			if (game->map.grid[i][j] == 'E')
				game->map.exit++;
			if (game->map.grid[i][j] == 'P')
				game->map.spawn++;
			j++;
		}
		i++;
	}
}

void	check_map_size(t_global *game)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(game->map.grid[i++]);
	while (game->map.grid[i])
	{
		if (ft_strlen(game->map.grid[i]) != ref)
		{
			free_exit(game, "Invalid map line length on line !", 1);
		}
		i++;
	}
	if (game->map.width == game->map.height)
	{
		free_exit(game, "Your map is square !", 1);
	}
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
	while(game->map.grid && game->map.grid[i])
	{
		free(game->map.grid[i++]);
	}
	free(game->map.grid);
	free(game);
	exit(1);
}

bool	check_chars_counts(t_global *game)
{
	if (game->map.collectible < 1)
	{
		return false;
	}
	if (game->map.exit < 1 || game->map.exit > 1)
	{
		return false;
	}
	if (game->map.spawn < 1 || game->map.spawn > 1)
	{
		return false;
	}
	return true;
}
