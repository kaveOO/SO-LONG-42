/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/12/01 00:27:17 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	args_checker(char *filename, int argc)
{
	if (argc < 2)
	{
		ft_printf("Error\nPlease enter map name !\n");
		exit(1);
	}
	else if (argc > 2)
	{
		ft_printf("Error\nYou have too much arguments !\n");
		exit(1);
	}
	if (!check_if_opened(filename))
	{
		ft_printf("Error\nInvalid map name !\n");
		exit(1);
	}
	if (!check_extension(filename, "ber"))
	{
		ft_printf("Error\nMap file extension is invalid !\n");
		exit(1);
	}
	ft_printf("Map (%s) opened!\n", filename);
}

int	get_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

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
int get_width(char *filename)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	free(line);
	get_next_line(-1);
	close(fd);
	return (width);
}
void	map_checker(char **map, int width, int height)
{
	t_elements *elements;

	elements = (t_elements *)ft_calloc(1, sizeof(t_elements));
	check_map_size(map, width, height);
	check_map_closure(map, width, height);
	check_map_char(map, width);
	count_map_chars(map, width, elements);
	if (!check_chars_counts(elements))
		free(elements), exit_free("Invalid characters count !", map);
}
void	check_map_closure(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = height - 1;
	while (map[j][i] != '\n')
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			exit_free("Invalid characters on first or/and last line !", map);
		while (j > 0)
		{
			if (map[j][width - 2] != '1' || map[j][0] != '1')
				exit_free("Invalid enclosure on sides !", map);
			j--;
		}
		i++;
	}
}
void	check_map_char(char **map, int width)
{
	size_t	i;
	size_t	j;
	char	*chars;

	i = 0;
	chars = "01CEP";
	while (map[i])
	{
		j = width - 2;
		while (map[i][j] && j > 0)
		{
			if (!strchr(chars, map[i][j]))
			{
				exit_free("Invalid characters in map !", map);
			}
			j--;
		}
		i++;
	}
}
void	count_map_chars(char **map, int width, t_elements *elements)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = width - 2;
		while (map[i][j] && j > 0)
		{
			if (strchr("C", map[i][j]))
				elements->collectible++;
			if (strchr("E", map[i][j]))
				elements->exit++;
			if (strchr("P", map[i][j]))
				elements->spawn++;
			j--;
		}
		i++;
	}
}

void	exit_free(char *str, char **map)
{
	if (!str)
		return ;
	printf("Error\n%s\n", str);
	free_map(map);
	exit(1);
}


void	check_map_size(char **map, int width, int height)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(map[i++]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ref)
		{
			printf("Error\nInvalid map line length on line !\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
	if (width == height)
	{
		printf("Error\nYour map is square !\n");
		free_map(map);
		exit(1);
	}
}

char	**fill_matrix(char **map, char *filename, int height)
{
	int		fd;
	int		i;
	char	*line;

	map = malloc(sizeof(char *) * (height + 1));
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map[0] = line;
	i = 1;
	while (i < height)
	{
		line = get_next_line(fd);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	get_next_line(-1);
	close(fd);
	return (map);
}
void	free_map(char **map)
{
	int i = 0;
	while(map && map[i])
		free(map[i++]);
	free(map);
}

/* int main(int argc, char **argv)
{
	args_checker(argv[1], argc);
	//t_global game;
	t_map 	*map;
	// map.height = 0;
	// map.width = 0;
	//game.map = &map;
	map = (t_map *)malloc(sizeof(t_map)); //free
	map->height = get_height(argv[1]);
	map->width = get_width(argv[1]);
	map->grid = fill_matrix(map->grid, argv[1], map->height);
	map_checker(map->grid, map->width, map->height);
	free_map(map->grid);
	//map_checker(map->grid);
	return 0;
} */

bool	check_chars_counts(t_elements *elements)
{
	if (elements->collectible < 1)
	{
		return false;
	}
	if (elements->exit < 1 || elements->exit > 1)
	{
		return false;
	}
	if (elements->spawn < 1 || elements->spawn > 1)
	{
		return false;
	}
	return true;
}
