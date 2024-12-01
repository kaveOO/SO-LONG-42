/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:10:51 by albillie          #+#    #+#             */
/*   Updated: 2024/12/01 18:13:39 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	args_checker(char *filename, int argc, t_map *map)
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
	map->filename = filename;
	ft_printf("Map (%s) opened!\n", filename);
}

void	get_height(t_map *map)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(map->filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	free(line);
	close(fd);
}
void get_width(t_map *map)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(map->filename, O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	map->width = ft_strlen(line);
	free(line);
	get_next_line(-1);
	close(fd);
}
void	map_checker(t_map *map)
{
	t_elements *elements;

	elements = (t_elements *)ft_calloc(1, sizeof(t_elements));
	get_height(map);
	get_width(map);
	fill_matrix(map);
	check_map_size(map);
	check_map_closure(map);
	check_map_char(map);
	count_map_chars(map, elements);
	if (!check_chars_counts(elements))
		free(elements), exit_free("Invalid characters count !", map->grid);
	map->w_height = map->height;
	map->w_width = map->width - 1;
}
void	check_map_closure(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[j][i])
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			exit_free("Invalid characters on first or/and last line !", map->grid);
		while (j > 0)
		{
			printf("droite >%c gauche %c", map->grid[j][map->width], map->grid[j][0]);
			if (map->grid[j][map->width - 4] != '1' || map->grid[j][0] != '1')
			{
				printf("%c %c", map->grid[j][map->width], map->grid[j][0]);
				exit_free("Invalid enclosure on sides !", map->grid);
			}
			j--;
		}
		i++;
	}
}
void	check_map_char(t_map *map)
{
	size_t	i;
	size_t	j;
	char	*chars;

	i = 0;
	chars = "01CEP";
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (!strchr(chars, map->grid[i][j]))
			{
				exit_free("Invalid characters in map !", map->grid);
			}
			j++;
		}
		i++;
	}
}
void	count_map_chars(t_map *map, t_elements *elements)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'C')
				elements->collectible++;
			if (map->grid[i][j] == 'E')
				elements->exit++;
			if (map->grid[i][j] == 'P')
				elements->spawn++;
			j++;
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


void	check_map_size(t_map *map)
{
	int		i;
	size_t	ref;

	i = 0;
	ref = ft_strlen(map->grid[i++]);
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != ref)
		{
			printf("Error\nInvalid map line length on line !\n");
			free_map(map->grid);
			exit(1);
		}
		i++;
	}
	if (map->width == map->height)
	{
		printf("Error\nYour map is square !\n");
		free_map(map->grid);
		exit(1);
	}
}

void	fill_matrix(t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;

	map->grid = malloc(sizeof(char *) * (map->height + 1));
	fd = open(map->filename, O_RDONLY);
	line = get_next_line(fd);
	tmp = line;
	tmp = ft_strtrim(tmp, "\n");
	free(line);
	map->grid[0] = tmp;
	i = 1;
	while (i < map->height)
	{
		line = get_next_line(fd);
		tmp = line;
		tmp = ft_strtrim(tmp, "\n");
		free(line);
		map->grid[i] = tmp;
		// printf("%s\n", map->grid[i]);
		i++;
	}
	map->grid[i] = NULL;
	get_next_line(-1);
	close(fd);
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
